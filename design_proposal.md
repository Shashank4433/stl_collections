# Design Proposal: Collections Library and Redis Lite

## 1. Project Overview

The objective of this project is to design and implement a reusable **Collections Library** in C++ without using Standard Template Library (STL) containers and utilize it to build **Redis Lite**, a simplified in-memory key-value database.

```text
DynamicArray → LinkedList → HashMap → Redis Lite
```
---

## 2. Design Objectives

* Learn manual memory management using `new` and `delete`
* Understand dynamic allocation and object lifetime management
* Build reusable template-based data structures
* Analyze performance and complexity trade-offs
* Implement deep copy semantics using copy constructors and assignment operators
* Develop a practical application (Redis Lite) using custom-built data structures

---

## 3. Executive Summary

This project implements core data structures commonly found in the C++ Standard Template Library without relying on STL containers.

The Collections Library focuses on:

* Dynamic memory management
* Generic programming using templates
* Efficient data structure implementation
* Algorithmic complexity analysis
* Software modularity and reusability

The completed library serves as the foundation for Redis Lite, enabling efficient in-memory key-value storage.

---

## 4. System Architecture

The project follows a layered architecture in which each component builds upon the previous layer:

```text
DynamicArray → LinkedList → HashMap → Redis Lite
```

### Layer Responsibilities

* **DynamicArray:** Provides dynamic contiguous storage with automatic resizing.
* **LinkedList:** Provides efficient node-based storage and supports collision handling.
* **HashMap:** Stores key-value pairs using separate chaining.
* **Redis Lite:** Offers an in-memory key-value interface built on HashMap.

This decomposition allows each data structure to be tested independently while maintaining high cohesion and low coupling.

---

## 5. DynamicArray Design

### Template Declaration

```cpp
template<typename T>
class DynamicArray;
```

### Design Details

Elements are stored in contiguous memory and resized dynamically.

* Initial capacity: `4`
* Resize policy: Double capacity when `size == capacity`

```text
newCapacity = capacity × 2
```

### Public API

| Method                                    | Time Complexity          | Description             |
| ----------------------------------------- | ------------------------ | ----------------------- |
| `DynamicArray()`                          | O(1)                     | Create empty array      |
| `~DynamicArray()`                         | O(n)                     | Release memory          |
| `DynamicArray(const DynamicArray& other)` | O(n)                     | Deep copy               |
| `operator=(const DynamicArray& other)`    | O(n)                     | Deep copy assignment    |
| `append(T value)`                         | O(1) average, O(n) worst | Add element at end      |
| `insert(int index, T value)`              | O(n)                     | Insert at position      |
| `remove(int index)`                       | O(n)                     | Delete element          |
| `get(int index)`                          | O(1)                     | Return element          |
| `set(int index, T value)`                 | O(1)                     | Update element          |
| `size()`                                  | O(1)                     | Return current size     |
| `capacity()`                              | O(1)                     | Return current capacity |
| `isEmpty()`                               | O(1)                     | Check if array is empty |
| `clear()`                                 | O(n)                     | Remove all elements     |
| `contains(T value)`                       | O(n)                     | Check if value exists   |
| `find(T value)`                           | O(n)                     | Return index of value   |

### Public API Declaration

```cpp
template<typename T>
class DynamicArray
{
private:
    T* data;
    int currentSize;
    int currentCapacity;

    void resize(int newCapacity);

public:
    DynamicArray();
    ~DynamicArray();
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);

    void append(const T& value);
    void insert(int index, const T& value);
    void remove(int index);

    T& get(int index);
    const T& get(int index) const;

    void set(int index, const T& value);

    int size() const;
    int capacity() const;
    bool isEmpty() const;

    void clear();

    bool contains(const T& value) const;
    int find(const T& value) const;
};
```

### Memory Representation

```text
data ──► [ element0 ][ element1 ][ element2 ] ...
size = 3, capacity = 4
```

---

## 6. LinkedList Design

### Template Declaration

```cpp
template<typename T>
class LinkedList;
```

### Design Details

The implementation uses a singly linked list because it reduces memory overhead compared to a doubly linked list.

Each node contains:

* Value
* Pointer to the next node

### Data Members

```cpp
Node<T>* head;
Node<T>* tail;
int currentSize;
```

### Public API

| Method                                | Time Complexity | Description                 |
| ------------------------------------- | --------------- | --------------------------- |
| `LinkedList()`                        | O(1)            | Create empty list           |
| `~LinkedList()`                       | O(n)            | Delete all nodes            |
| `LinkedList(const LinkedList& other)` | O(n)            | Deep copy                   |
| `operator=(const LinkedList& other)`  | O(n)            | Deep copy assignment        |
| `insertFront(T value)`                | O(1)            | Insert at head              |
| `insertBack(T value)`                 | O(1)            | Insert at tail              |
| `deleteFront()`                       | O(1)            | Remove head node            |
| `deleteBack()`                        | O(n)            | Remove last node            |
| `insert(int index, T value)`          | O(n)            | Insert at position          |
| `remove(int index)`                   | O(n)            | Delete node at position     |
| `get(int index)`                      | O(n)            | Return element at index     |
| `set(int index, T value)`             | O(n)            | Update element at index     |
| `find(T value)`                       | O(n)            | Return index of value       |
| `contains(T value)`                   | O(n)            | Check if value exists       |
| `search(T value)`                     | O(n)            | Linear search               |
| `size()`                              | O(1)            | Return stored size          |
| `isEmpty()`                           | O(1)            | Check whether list is empty |
| `clear()`                             | O(n)            | Delete all nodes            |
| `display()`                           | O(n)            | Traverse all nodes          |

### Public API Declaration

```cpp
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
```

### Memory Representation

```text
head → [data|next] → [data|next] → [data|null]
 ↑
tail
```

---

## 7. HashMap Design

### Template Declaration

```cpp
template<typename K, typename V>
class HashMap;
```

### Design Details

The HashMap stores data as key-value pairs using separate chaining.

* Initial bucket count: `8`

```text
loadFactor = size / bucketCount
```

* Rehash threshold: `0.75`

```text
bucketCount *= 2
```

### Bucket Node Structure

```cpp
template<typename K, typename V>
struct Entry
{
    K key;
    V value;
    Entry* next;
};
```

### Public API

| Method                            | Time Complexity | Description              |
| --------------------------------- | --------------- | ------------------------ |
| `HashMap()`                       | O(1)            | Initialize buckets       |
| `~HashMap()`                      | O(n)            | Delete all entries       |
| `HashMap(const HashMap& other)`   | O(n)            | Deep copy                |
| `operator=(const HashMap& other)` | O(n)            | Deep copy assignment     |
| `set(K key, V value)`             | O(1) average    | Insert or update key     |
| `get(K key)`                      | O(1) average    | Retrieve value           |
| `remove(K key)`                   | O(1) average    | Remove entry             |
| `exists(K key)`                   | O(1) average    | Check key existence      |
| `find(K key)`                     | O(1) average    | Find associated entry    |
| `size()`                          | O(1)            | Return current size      |
| `isEmpty()`                       | O(1)            | Check if map is empty    |
| `clear()`                         | O(n)            | Remove all entries       |
| `loadFactor()`                    | O(1)            | Calculate load factor    |
| `bucketCount()`                   | O(1)            | Return number of buckets |
| `rehash(int newBucketCount)`      | O(n)            | Rebuild hash table       |

### Public API Declaration

```cpp
template<typename K, typename V>
class HashMap
{
private:
    struct Entry
    {
        K key;
        V value;
        Entry* next;

        Entry(const K& k, const V& v)
            : key(k), value(v), next(nullptr) {}
    };

    Entry** buckets;
    int currentSize;
    int currentBucketCount;

    size_t hashKey(const K& key) const;
    void rehash(int newBucketCount);

public:
    HashMap();
    ~HashMap();
    HashMap(const HashMap& other);
    HashMap& operator=(const HashMap& other);

    void set(const K& key, const V& value);
    V get(const K& key) const;
    void remove(const K& key);

    bool exists(const K& key) const;

    int size() const;
    bool isEmpty() const;

    void clear();

    double loadFactor() const;
    int bucketCount() const;
};
```

### Memory Representation

```text
bucket[0] → Entry → Entry → null
bucket[1] → null
```

### Hash Functions

| Type         | Hash Method                    |
| ------------ | ------------------------------ |
| `int`        | `value % bucketCount`          |
| `char`       | ASCII value                    |
| `string`     | Polynomial rolling hash        |
| Custom class | User-defined `hash()` function |

---

## 8. Error Handling

| Operation                 | Action                       |
| ------------------------- | ---------------------------- |
| Invalid array index       | Print `"Invalid Index"`      |
| Empty list deletion       | Print suitable error message |
| Missing HashMap key       | Print suitable error message |
| Memory allocation failure | Handle gracefully            |

---

## 9. Design Decisions and Trade-Offs

### DynamicArray

**Alternatives considered:**

* Increase capacity by `1.5×`
* Double capacity

**Selected approach:** Double capacity

**Reason:** Provides amortized `O(1)` append performance.

### LinkedList

**Alternatives considered:**

* Doubly linked list
* Singly linked list

**Selected approach:** Singly linked list

**Reason:** Reduces memory consumption and simplifies implementation.

### HashMap

**Alternatives considered:**

* Open addressing
* Separate chaining

**Selected approach:** Separate chaining

**Reasons:**

* Easier deletion
* Simpler implementation
* Better handling of collisions

---

## 10. Testing Plan

### DynamicArray

* Append elements until capacity doubles
* Insert and remove at beginning, middle, and end
* Verify invalid index handling
* Verify deep copy behavior

### LinkedList

* Test insertion and deletion on empty lists
* Verify head and tail pointer updates
* Test single-node deletion
* Verify deep copy behavior

### HashMap

* Insert keys that collide into the same bucket
* Verify separate chaining behavior
* Trigger rehashing at load factor `0.75`
* Test removal from the middle of a chain
* Verify retrieval of non-existent keys

---

## 11. Conclusion

This project emphasizes modularity, maintainability, and efficient data management through the implementation of reusable template-based data structures.

By building Redis Lite on top of custom implementations of `DynamicArray`, `LinkedList`, and `HashMap`, the project provides practical experience in memory management, templates, algorithmic analysis, and software design principles while maintaining a scalable and extensible architecture.
