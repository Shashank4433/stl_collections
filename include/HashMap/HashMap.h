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

#endif
