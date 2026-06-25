# Session 1

**Date:** 25-06-2026  
**Duration:** 90 minutes  

## Goal

Implement core HashMap operations including collision handling, insertion, deletion, and search functionality using separate chaining.

## Work Done

* Implemented `insert(K key, V value)` with collision handling.
* Implemented separate chaining using linked lists inside buckets.
* Implemented `get(K key)` for retrieving values.
* Implemented `remove(K key)` with proper node deletion.
* Implemented `containsKey(K key)` using traversal in bucket list.
* Implemented `update(K key, V value)` for modifying existing values.
* Maintained `currentSize` correctly during insert and delete.
* Handled collisions by inserting nodes at head of linked list.
* Ensured no memory leaks during deletion.
* Tested multiple keys mapping to same bucket index.
* Verified search and retrieval operations.

## Problem Encountered

Collision handling required careful pointer updates, especially during deletion from middle of linked list inside a bucket.

## What I Tried

* Inserted multiple keys with same hash index.
* Tested delete operation on head, middle, and last node of bucket list.
* Verified get() and containsKey() behavior for existing and non-existing keys.
* Checked size updates after insert and remove operations.

## Outcome

Core HashMap functionality including insertion, deletion, and search is working correctly with proper collision handling.

## Build Status

* insert() implemented
* remove() implemented
* get() implemented
* update() implemented
* containsKey() implemented
* collision handling working
* separate chaining functional
* size tracking verified
