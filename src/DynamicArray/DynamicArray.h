#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include <cstdlib>

template<typename T>
class DynamicArray
{
private:
    T* data;
    int currentSize;
    int currentCapacity;

    void resize();

public:
    DynamicArray();
    ~DynamicArray();

    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);

    void append(const T& value);
    void insert(int index, const T& value);
    void remove(int index);

    T get(int index) const;
    void set(int index, const T& value);

    int size() const;
    int capacity() const;
    bool isEmpty() const;

    void clear();

    bool contains(const T& value) const;
    int find(const T& value) const;
};

template<typename T>
DynamicArray<T>::DynamicArray()
{
    currentCapacity = 4;
    currentSize = 0;
    data = new T[currentCapacity];
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] data;
}

template<typename T>
void DynamicArray<T>::resize()
{
    currentCapacity *= 2;

    T* temp = new T[currentCapacity];

    for (int i = 0; i < currentSize; i++)
    {
        temp[i] = data[i];
    }

    delete[] data;
    data = temp;
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other)
{
    currentSize = other.currentSize;
    currentCapacity = other.currentCapacity;

    data = new T[currentCapacity];

    for (int i = 0; i < currentSize; i++)
    {
        data[i] = other.data[i];
    }
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other)
{
    if (this != &other)
    {
        T* temp = new T[other.currentCapacity];
        for (int i = 0; i < other.currentSize; i++)
        {
            temp[i] = other.data[i];
        }

        delete[] data;
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

    data[currentSize++] = value;
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

    for (int i = currentSize; i > index; i--)
    {
        data[i] = data[i - 1];
    }

    data[index] = value;
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

    data[currentSize - 1] = T();
    currentSize--;
}

template<typename T>
T DynamicArray<T>::get(int index) const
{
    if (index < 0 || index >= currentSize)
    {
        std::cout << "Invalid Index" << std::endl;
        return T();
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
        data[i] = T();
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

#endif