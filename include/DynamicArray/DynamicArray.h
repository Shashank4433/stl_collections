#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include <cstdlib>
#include <new>
#include <stdexcept>

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

#endif