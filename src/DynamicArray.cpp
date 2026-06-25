template<typename T>
DynamicArray<T>::DynamicArray()
{
    currentCapacity = 4;
    currentSize = 0;
    data = (T*)std::malloc(currentCapacity * sizeof(T));
    if (data == nullptr)
    {
        throw std::bad_alloc();
    }
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
    if (data != nullptr)
    {
        for (int i = 0; i < currentSize; i++)
        {
            data[i].~T();
        }
        std::free(data);
    }
}

template<typename T>
void DynamicArray<T>::resize()
{
    currentCapacity *= 2;

    T* temp = (T*)std::malloc(currentCapacity * sizeof(T));
    if (temp == nullptr)
    {
        throw std::bad_alloc();
    }

    for (int i = 0; i < currentSize; i++)
    {
        new (&temp[i]) T(data[i]);
        data[i].~T();
    }

    std::free(data);
    data = temp;
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other)
{
    currentSize = other.currentSize;
    currentCapacity = other.currentCapacity;

    data = (T*)std::malloc(currentCapacity * sizeof(T));
    if (data == nullptr)
    {
        throw std::bad_alloc();
    }

    for (int i = 0; i < currentSize; i++)
    {
        new (&data[i]) T(other.data[i]);
    }
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other)
{
    if (this != &other)
    {
        T* temp = (T*)std::malloc(other.currentCapacity * sizeof(T));
        if (temp == nullptr)
        {
            throw std::bad_alloc();
        }
        for (int i = 0; i < other.currentSize; i++)
        {
            new (&temp[i]) T(other.data[i]);
        }

        for (int i = 0; i < currentSize; i++)
        {
            data[i].~T();
        }
        std::free(data);

        data = temp;
        currentSize = other.currentSize;
        currentCapacity = other.currentCapacity;
    }

    return *this;
}

template<typename T>
void DynamicArray<T>::append(const T& value)
{
    if (currentSize == currentCapacity)
    {
        resize();
    }

    new (&data[currentSize]) T(value);
    currentSize++;
}

template<typename T>
void DynamicArray<T>::insert(int index, const T& value)
{
    if (index < 0 || index > currentSize)
    {
        std::cout << "Invalid Index" << std::endl;
        return;
    }

    if (currentSize == currentCapacity)
    {
        resize();
    }

    if (index == currentSize)
    {
        new (&data[index]) T(value);
    }
    else
    {
        new (&data[currentSize]) T(data[currentSize - 1]);
        for (int i = currentSize - 1; i > index; i--)
        {
            data[i] = data[i - 1];
        }
        data[index] = value;
    }
    currentSize++;
}

template<typename T>
void DynamicArray<T>::remove(int index)
{
    if (index < 0 || index >= currentSize)
    {
        std::cout << "Invalid Index" << std::endl;
        return;
    }

    for (int i = index; i < currentSize - 1; i++)
    {
        data[i] = data[i + 1];
    }

    data[currentSize - 1].~T();
    currentSize--;
}

template<typename T>
T DynamicArray<T>::get(int index) const
{
    if (index < 0 || index >= currentSize)
    {
        throw std::out_of_range("Invalid Index");
    }

    return data[index];
}

template<typename T>
void DynamicArray<T>::set(int index, const T& value)
{
    if (index < 0 || index >= currentSize)
    {
        std::cout << "Invalid Index" << std::endl;
        return;
    }

    data[index] = value;
}

template<typename T>
int DynamicArray<T>::size() const
{
    return currentSize;
}

template<typename T>
int DynamicArray<T>::capacity() const
{
    return currentCapacity;
}

template<typename T>
bool DynamicArray<T>::isEmpty() const
{
    return currentSize == 0;
}

template<typename T>
void DynamicArray<T>::clear()
{
    for (int i = 0; i < currentSize; i++)
    {
        data[i].~T();
    }
    currentSize = 0;
}

template<typename T>
bool DynamicArray<T>::contains(const T& value) const
{
    return find(value) != -1;
}

template<typename T>
int DynamicArray<T>::find(const T& value) const
{
    for (int i = 0; i < currentSize; i++)
    {
        if (data[i] == value)
        {
            return i;
        }
    }

    return -1;
}