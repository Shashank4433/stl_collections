# Session 2

**Date:** 25-06-2026  
**Duration:** 90 minutes  

## Goal

Implement advanced HashMap features including rehashing, deep copy, destructor, and performance optimization with full testing.

## Work Done

* Implemented `rehash()` to double bucket capacity.
* Implemented load factor calculation:
  - `loadFactor = currentSize / currentCapacity`
* Added automatic resizing when load factor exceeds 0.75.
* Implemented destructor to free all dynamically allocated memory.
* Implemented `clear()` function to reset HashMap.
* Implemented copy constructor for deep copying.
* Implemented copy assignment operator.
* Ensured all nodes are reinserted correctly during rehash.
* Verified no memory leaks during resizing and deletion.
* Tested HashMap with multiple data types (int-string, string-int).
* Performed stress testing with large number of insertions.
* Validated correctness after multiple rehash operations.

## Problem Encountered

Rehashing required careful reinsertion of nodes because old bucket structure becomes invalid after resizing.

## What I Tried

* Inserted large dataset to trigger multiple rehash operations.
* Verified correctness of key-value pairs after resizing.
* Tested deep copy behavior between two HashMap objects.
* Ensured original and copied HashMaps operate independently.
* Checked destructor to confirm full memory cleanup.

## Outcome

Fully functional HashMap implemented with dynamic resizing, deep copy support, and safe memory management.

## Build Status

* rehash() implemented
* destructor implemented
* clear() implemented
* copy constructor implemented
* assignment operator implemented
* load factor logic implemented
* deep copy verified
* memory leak checks passed
* HashMap implementation completed successfully