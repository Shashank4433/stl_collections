#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template<typename T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node* next;

        Node(const T& value)
            : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int currentSize;

public:
    LinkedList();
    ~LinkedList();

    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);

    void insertFront(const T& value);
    void insertBack(const T& value);

    void deleteFront();
    void deleteBack();

    void insert(int index, const T& value);
    void remove(int index);

    T& get(int index);
    const T& get(int index) const;

    void set(int index, const T& value);

    int find(const T& value) const;
    bool contains(const T& value) const;
    bool search(const T& value) const;

    int size() const;
    bool isEmpty() const;

    void clear();
    void display() const;
};


#endif
