template<typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    currentSize = 0;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
    head = nullptr;
    tail = nullptr;
    currentSize = 0;

    Node* temp = other.head;
    while (temp != nullptr)
    {
        insertBack(temp->data);
        temp = temp->next;
    }
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
    if (this != &other)
    {
        clear();
        Node* temp = other.head;
        while (temp != nullptr)
        {
            insertBack(temp->data);
            temp = temp->next;
        }
    }
    return *this;
}

template<typename T>
void LinkedList<T>::insertFront(const T& value)
{
    Node* newNode = new Node(value);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    currentSize++;
}

template<typename T>
void LinkedList<T>::insertBack(const T& value)
{
    Node* newNode = new Node(value);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    currentSize++;
}

template<typename T>
void LinkedList<T>::deleteFront()
{
    if (head == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    currentSize--;
    if (head == nullptr)
    {
        tail = nullptr;
    }
}

template<typename T>
void LinkedList<T>::deleteBack()
{
    if (head == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        currentSize = 0;
        return;
    }
    Node* temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = nullptr;
    currentSize--;
}

template<typename T>
void LinkedList<T>::insert(int index, const T& value)
{
    if (index < 0 || index > currentSize)
    {
        std::cout << "Invalid Index" << std::endl;
        return;
    }
    if (index == 0)
    {
        insertFront(value);
        return;
    }
    if (index == currentSize)
    {
        insertBack(value);
        return;
    }
    Node* temp = head;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
    currentSize++;
}

template<typename T>
void LinkedList<T>::remove(int index)
{
    if (index < 0 || index >= currentSize)
    {
        std::cout << "Invalid Index" << std::endl;
        return;
    }
    if (index == 0)
    {
        deleteFront();
        return;
    }
    Node* temp = head;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete == tail)
    {
        tail = temp;
    }
    delete toDelete;
    currentSize--;
}

template<typename T>
T& LinkedList<T>::get(int index)
{
    if (index < 0 || index >= currentSize)
    {
        std::cout << "Invalid Index" << std::endl;
        static T dummy;
        return dummy;
    }
    Node* temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

template<typename T>
const T& LinkedList<T>::get(int index) const
{
    if (index < 0 || index >= currentSize)
    {
        std::cout << "Invalid Index" << std::endl;
        static T dummy;
        return dummy;
    }
    Node* temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

template<typename T>
void LinkedList<T>::set(int index, const T& value)
{
    if (index < 0 || index >= currentSize)
    {
        std::cout << "Invalid Index" << std::endl;
        return;
    }
    Node* temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    temp->data = value;
}

template<typename T>
int LinkedList<T>::find(const T& value) const
{
    Node* temp = head;
    int index = 0;
    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

template<typename T>
bool LinkedList<T>::contains(const T& value) const
{
    return find(value) != -1;
}

template<typename T>
bool LinkedList<T>::search(const T& value) const
{
    return contains(value);
}

template<typename T>
int LinkedList<T>::size() const
{
    return currentSize;
}

template<typename T>
bool LinkedList<T>::isEmpty() const
{
    return currentSize == 0;
}

template<typename T>
void LinkedList<T>::clear()
{
    Node* temp = head;
    while (temp != nullptr)
    {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    head = nullptr;
    tail = nullptr;
    currentSize = 0;
}

template<typename T>
void LinkedList<T>::display() const
{
    Node* temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
