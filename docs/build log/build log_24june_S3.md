# Session 3

**Date:** 24-06-2026  
**Duration:** 90 minutes  

## Goal

Design and implement the basic structure of HashMap using separate chaining and set up core data members, constructor, and bucket system.

## Work Done

* Designed `HashMap<K, V>` template class structure.
* Created `Node<K,V>` structure for storing key-value pairs.
* Implemented bucket array using pointer-based dynamic memory:
  - `Node<K,V>** buckets`
* Initialized core variables:
  - `currentSize`
  - `currentCapacity`
* Set default capacity to 8.
* Initialized all buckets to `nullptr`.
* Implemented constructor for HashMap initialization.
* Designed hash function logic for mapping keys to bucket index.
* Implemented basic node insertion structure (without collision handling logic fully completed).
* Defined separate chaining approach for collision handling.
* Verified basic insertion into empty buckets.

## Problem Encountered

Understanding bucket-based memory allocation and ensuring all pointers are properly initialized to `nullptr` was critical to avoid segmentation faults.

## What I Tried

* Tested bucket initialization manually.
* Inserted sample key-value pairs into empty buckets.
* Verified hash index calculation logic.
* Checked memory allocation for bucket array.

## Outcome

Successfully created base structure of HashMap with working bucket system and node design. Basic insertion into empty buckets works correctly.

## Build Status

* Compilation Successful
* HashMap structure created
* Node structure implemented
* Bucket array initialized
* Constructor implemented
* Hash function logic added
* Basic insertion verified