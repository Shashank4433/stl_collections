#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <string>

// Custom Hash Template Helper
template<typename K>
struct CustomHash
{
    size_t operator()(const K& key) const
    {
        return (size_t)key;
    }   // convert key into hash value needed because hashmap does not store key directly
};

// Specialization for float
template<>
struct CustomHash<float>
{
    size_t operator()(const float& key) const
    {
        union {
            float f;
            size_t i;
        } u;
        u.i = 0; //to avoid garbage values
        u.f = key;
        return u.i;
    }
};

// Specialization for double
template<>
struct CustomHash<double>
{
    size_t operator()(const double& key) const
    {
        union {
            double d;
            size_t i;
        } u;
        u.i = 0;
        u.d = key;
        return u.i;
    }
};

// Specialization for std::string (Polynomial rolling hash)
template<>
struct CustomHash<std::string>
{
    size_t operator()(const std::string& key) const
    {
        size_t hash = 5381;
        for (size_t i = 0; i < key.length(); i++)
        {
            hash = ((hash << 5) + hash) + key[i];
        }
        return hash;
    }
};

// Specialization for const char* (Polynomial rolling hash)
template<>
struct CustomHash<const char*>
{
    size_t operator()(const char* key) const
    {
        size_t hash = 5381;
        while (*key)
        {
            hash = ((hash << 5) + hash) + *key;
            key++;
        }
        return hash;
    }
};

template<typename K, typename V>
struct Node
{
    K key;
    V value;
    Node* next;

    Node(const K& k, const V& v)
        : key(k), value(v), next(nullptr) {}
};

template<typename K, typename V>
class HashMap
{
private:
    Node<K, V>** buckets;
    int currentSize;
    int currentCapacity;

    int hashFunction(const K& key) const;

public:
    HashMap();
    ~HashMap();

    HashMap(const HashMap& other);
    HashMap& operator=(const HashMap& other);

    void insert(const K& key, const V& value);
    void remove(const K& key);
    V get(const K& key) const;
    void update(const K& key, const V& value);
    bool containsKey(const K& key) const;

    int size() const;
    bool isEmpty() const;
    void clear();
    void display() const;
    void rehash();

    double loadFactor() const;
    int bucketCount() const;
};

template<typename K, typename V>
HashMap<K, V>::HashMap()
{
    currentSize = 0;
    currentCapacity = 8;
    buckets = new Node<K, V>*[currentCapacity];
    for (int i = 0; i < currentCapacity; i++)
    {
        buckets[i] = nullptr;
    }
}

template<typename K, typename V>
HashMap<K, V>::~HashMap()
{
    clear();
    delete[] buckets;
}

template<typename K, typename V>
HashMap<K, V>::HashMap(const HashMap<K, V>& other)
{
    currentSize = 0;
    currentCapacity = other.currentCapacity;
    buckets = new Node<K, V>*[currentCapacity];
    for (int i = 0; i < currentCapacity; i++)
    {
        buckets[i] = nullptr;
    }

    for (int i = 0; i < other.currentCapacity; i++)
    {
        Node<K, V>* temp = other.buckets[i];
        while (temp != nullptr)
        {
            insert(temp->key, temp->value);
            temp = temp->next;
        }
    }
}

template<typename K, typename V>
HashMap<K, V>& HashMap<K, V>::operator=(const HashMap<K, V>& other)
{
    if (this != &other)
    {
        clear();
        delete[] buckets;

        currentCapacity = other.currentCapacity;
        buckets = new Node<K, V>*[currentCapacity];
        for (int i = 0; i < currentCapacity; i++)
        {
            buckets[i] = nullptr;
        }

        for (int i = 0; i < other.currentCapacity; i++)
        {
            Node<K, V>* temp = other.buckets[i];
            while (temp != nullptr)
            {
                insert(temp->key, temp->value);
                temp = temp->next;
            }
        }
    }
    return *this;
}

template<typename K, typename V>
int HashMap<K, V>::hashFunction(const K& key) const
{
    CustomHash<K> hasher;
    size_t hashValue = hasher(key);
    return hashValue % currentCapacity;
}

template<typename K, typename V>
void HashMap<K, V>::insert(const K& key, const V& value)
{
    int index = hashFunction(key);
    Node<K, V>* temp = buckets[index];
    while (temp != nullptr)
    {
        if (temp->key == key)
        {
            temp->value = value;
            return;
        }
        temp = temp->next;
    }

    Node<K, V>* newNode = new Node<K, V>(key, value);
    newNode->next = buckets[index];
    buckets[index] = newNode;
    currentSize++;

    if ((double)currentSize / currentCapacity > 0.75)
    {
        rehash();
    }
}

template<typename K, typename V>
void HashMap<K, V>::remove(const K& key)
{
    int index = hashFunction(key);
    Node<K, V>* temp = buckets[index];
    Node<K, V>* prev = nullptr;

    while (temp != nullptr)
    {
        if (temp->key == key)
        {
            if (prev == nullptr)
            {
                buckets[index] = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            delete temp;
            currentSize--;
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    std::cout << "Key not found" << std::endl;
}

template<typename K, typename V>
V HashMap<K, V>::get(const K& key) const
{
    int index = hashFunction(key);
    Node<K, V>* temp = buckets[index];
    while (temp != nullptr)
    {
        if (temp->key == key)
        {
            return temp->value;
        }
        temp = temp->next;
    }
    std::cout << "Key not found" << std::endl;
    return V();
}

template<typename K, typename V>
void HashMap<K, V>::update(const K& key, const V& value)
{
    int index = hashFunction(key);
    Node<K, V>* temp = buckets[index];
    while (temp != nullptr)
    {
        if (temp->key == key)
        {
            temp->value = value;
            return;
        }
        temp = temp->next;
    }
    std::cout << "Key not found" << std::endl;
}

template<typename K, typename V>
bool HashMap<K, V>::containsKey(const K& key) const
{
    int index = hashFunction(key);
    Node<K, V>* temp = buckets[index];
    while (temp != nullptr)
    {
        if (temp->key == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template<typename K, typename V>
int HashMap<K, V>::size() const
{
    return currentSize;
}

template<typename K, typename V>
bool HashMap<K, V>::isEmpty() const
{
    return currentSize == 0;
}

template<typename K, typename V>
void HashMap<K, V>::clear()
{
    for (int i = 0; i < currentCapacity; i++)
    {
        Node<K, V>* temp = buckets[i];
        while (temp != nullptr)
        {
            Node<K, V>* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        buckets[i] = nullptr;
    }
    currentSize = 0;
}

template<typename K, typename V>
void HashMap<K, V>::display() const
{
    for (int i = 0; i < currentCapacity; i++)
    {
        std::cout << "Index " << i << " -> ";
        Node<K, V>* temp = buckets[i];
        while (temp != nullptr)
        {
            std::cout << "[" << temp->key << "," << temp->value << "] -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }
}

template<typename K, typename V>
void HashMap<K, V>::rehash()
{
    int oldCapacity = currentCapacity;
    currentCapacity *= 2;

    Node<K, V>** oldBuckets = buckets;
    buckets = new Node<K, V>*[currentCapacity];
    for (int i = 0; i < currentCapacity; i++)
    {
        buckets[i] = nullptr;
    }

    currentSize = 0;

    for (int i = 0; i < oldCapacity; i++)
    {
        Node<K, V>* temp = oldBuckets[i];
        while (temp != nullptr)
        {
            insert(temp->key, temp->value);
            Node<K, V>* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

    delete[] oldBuckets;
}

template<typename K, typename V>
double HashMap<K, V>::loadFactor() const
{
    return (double)currentSize / currentCapacity;
}

template<typename K, typename V>
int HashMap<K, V>::bucketCount() const
{
    return currentCapacity;
}

#endif
