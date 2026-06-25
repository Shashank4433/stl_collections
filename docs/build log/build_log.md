 # Development Session Log

**Session:** 1
**Date:** 23-06-2026
**Duration:** 60 mins

## Work Completed

* Initialized the project workspace and created separate folders for source code, headers, and testing files.
* Carefully reviewed the project requirements to identify the main data structures and implementation sequence.
* Chosen a template-based approach for the `DynamicArray` to support multiple data types without code duplication.
* Studied different memory allocation strategies and explored the feasibility of using C-style allocation functions for dynamic storage management.
* Drafted the initial structure of the `DynamicArray` class, including data members required for size and capacity tracking.
* Outlined the public interface of the container by defining the key function declarations needed for future development.

## Build Status

* Development environment configured successfully.
* Core project files have been created and organized.
* No source code implementation has been compiled yet.
* Build and execution testing are scheduled for upcoming sessions.

## Challenges / Notes

* Explored the relationship between templates and manual memory allocation mechanisms.
* Considered potential issues when storing complex objects inside dynamically allocated memory.
* Identified the need for proper object lifecycle management when working without standard container libraries.
* Additional investigation is required to ensure safe memory handling and prevent resource leaks.

## Planned Tasks

* Implement the constructor responsible for initializing the container state.
* Develop memory deallocation procedures within the destructor.
* Create the resizing mechanism to expand storage when capacity limits are reached.
* Implement append and insert operations for adding elements to the array.
* Write a simple testing program to verify correctness of the implemented functionality.

**Session:** 2

**Date:** 24-06-2026

**Duration:** 60 min

## Work Completed

* Created the `DynamicArray` template class structure according to the project design proposal.
* Implemented the default constructor to initialize the dynamic array with a default capacity and size values.
* Allocated memory dynamically using `calloc()` for storing array elements.
* Implemented the destructor to release allocated memory using `free()` and prevent memory leaks.
* Developed the `resize()` function to increase the capacity of the array when it becomes full.
* Implemented memory reallocation logic to preserve existing elements during capacity expansion.
* Implemented the `append()` method to add elements at the end of the dynamic array.
* Added automatic resizing functionality within `append()` to support dynamic growth.
* Implemented basic utility functions including `size()`, `capacity()`, and `isEmpty()`.

## Build Status

* DynamicArray class structure completed successfully.
* Constructor, destructor, resize, and append methods implemented and tested.
* Dynamic memory allocation and deallocation functioning correctly.
* Project compiles successfully without syntax errors.
* Basic dynamic array operations working as expected.

## Challenges / Notes

* Studied the differences between `new/delete` and `malloc/calloc/free` memory management techniques.
* Faced template-related compilation issues while separating declarations and implementations into header and source files.
* Learned that template implementations must be visible during compilation and require special handling when split across multiple files.
* Implemented safeguards to handle invalid memory allocation scenarios.
* Observed that C-style memory management functions do not automatically invoke constructors and destructors for user-defined types.

## Planned Tasks

* Implement `insert()` functionality for adding elements at specific positions.
* Implement `remove()` method for deleting elements from the array.
* Develop `get()` and `set()` methods for element access and modification.
* Implement `contains()` and `find()` methods for searching operations.
* Develop copy constructor and copy assignment operator to support deep copying.
* Create comprehensive test cases to validate all DynamicArray operations.
* Begin integration of LinkedList implementation according to the project proposal.


## Session 3

**Date:** 23-06-2026

**Duration:** 90 minutes

**Goal:**

Complete the implementation of all remaining DynamicArray methods and validate the container using different template data types.

**Problem Encountered:**

The DynamicArray implementation performed correctly with primitive data types such as `int`, `float`, and `char`, but unexpected behavior was observed when testing with `std::string`. String elements were not being copied or displayed correctly after insertion and resizing operations.

**What I Tried:**

* Implemented the remaining DynamicArray methods including insertion, removal, and search operations.
* Tested the container using multiple primitive data types.
* Added debugging statements to monitor stored values during execution.
* Verified the behavior of copy constructor and assignment operator.
* Examined the resize mechanism and memory reallocation logic.
* Researched the interaction between templates and low-level memory management functions.
* Compared the behavior of primitive types and object types stored inside the container.

**Outcome:**

Successfully completed the implementation of all planned DynamicArray methods and verified correct functionality for primitive data types. Through testing and analysis, identified limitations associated with low-level memory management techniques when storing object types. Established a clear understanding of the additional steps required to safely support complex C++ objects within a generic container.

---

# Session 4

**Date:** 23-06-2026

**Duration:** 120 min

## Goal

Fix the issue where DynamicArray was not handling object types correctly and improve overall template compatibility.

## Work Done

* Conducted additional testing using `std::string`.
* Investigated memory allocation and resizing behavior.
* Studied object lifecycle management in C++.
* Improved the resize implementation to better preserve stored values.
* Implemented deep-copy functionality through a copy constructor.
* Implemented copy assignment operator for safe object copying.
* Tested the DynamicArray using both primitive and non-primitive types.
* Validated insertion, deletion, search, and update operations after modifications.

## Problem Faced

The DynamicArray behaved correctly when tested with:

* `int`
* `float`
* `char`

However, when tested using:

```cpp
DynamicArray<string> arr;
```

the program compiled successfully but failed to display expected results. The application terminated without producing any output, making it difficult to identify the source of the problem.

## Analysis

After extensive debugging and research, the following observations were made:

* Raw memory allocation functions only reserve memory space.
* Object construction and destruction are not automatically managed.
* Direct memory relocation techniques are not suitable for all object types.
* Complex types such as `std::string` require proper object lifecycle handling.
* Additional care is needed when designing template containers that support both primitive and object data types.

## Solution

To improve reliability and type compatibility:

* Revised the resizing approach to avoid unsafe memory relocation.
* Implemented controlled element copying during capacity expansion.
* Added deep-copy support through copy constructor and assignment operator.
* Improved memory cleanup procedures.
* Performed validation across different template parameter types.
* Retested all major DynamicArray operations after applying modifications.

## Result

The `DynamicArray` template container has been successfully refactored from unsafe C-style memory management (`calloc`/`free`) to modern C++ standard allocation (`new[]`/`delete[]`). This ensures proper construction and destruction of object types (like `std::string`) stored inside the container, resolving previous issues with undefined behavior and memory leaks.

**Successfully Validated Types:**
* Primitive: `int`, `float`, `char`
* Object/Class: `std::string` (and tracker classes with non-trivial lifecycle management)

**Verified Operations:**
* `append()` - element insertion at the end with dynamic capacity doubling
* `insert()` - element insertion at specific indices with correct shifting
* `remove()` - element removal at specific indices, properly resetting freed slots to `T()` to release object resources
* `get()` and `set()` - bounds-checked element access and modification
* `find()` and `contains()` - value-based searching and membership checks
* `clear()` - resetting the array size to 0 while calling destructors/releasing resources of all stored objects

## Build Status

* Compilation Successful
* DynamicArray implementation completed
* Deep-copy functionality verified
* Multiple data type testing completed
* Memory management improvements validated

# Session 1

**Date:** 24-06-2026

**Duration:** 90 minutes

## Goal

Implement the basic structure of the LinkedList template class and develop core insertion and utility operations.

## Work Done

* Created the LinkedList template class and Node structure.
* Implemented the Node constructor to initialize data and next pointer.
* Added data members `head`, `tail`, and `currentSize`.
* Implemented the default constructor to initialize an empty linked list.
* Implemented `insertFront()` to insert elements at the beginning of the list.
* Implemented `insertBack()` to insert elements at the end of the list using the tail pointer.
* Implemented `size()` to return the current number of nodes.
* Implemented `isEmpty()` to check whether the list contains any elements.
* Implemented `display()` to traverse and print all elements in the list.
* Tested insertion operations using integer data types.

## Problem Encountered

While implementing insertion operations, special handling was required for an empty list. Inserting the first node had to update both `head` and `tail` pointers correctly.

## What I Tried

* Tested insertion into an empty list.
* Tested insertion at the front and back multiple times.
* Verified pointer updates after each insertion.
* Checked whether `currentSize` was updated correctly.

## Outcome

Successfully implemented the core LinkedList structure and insertion operations. The list correctly maintains node connections, updates pointers, and stores elements dynamically.

## Build Status

* Compilation Successful
* Node structure implemented
* Constructor implemented
* insertFront() implemented
* insertBack() implemented
* size() and isEmpty() implemented
* display() implemented
* Basic LinkedList functionality verified

---
# Session 2

**Date:** 24-06-2026

**Duration:** 90 minutes

## Goal

Complete the remaining LinkedList operations, implement deep-copy functionality, and perform comprehensive testing.

## Work Done

* Implemented `deleteFront()` to remove the first node.
* Implemented `deleteBack()` to remove the last node.
* Implemented `insert(int index, const T& value)` for insertion at specific positions.
* Implemented `remove(int index)` for deletion at specific positions.
* Implemented both versions of `get()` for element access.
* Implemented `set()` to modify existing values.
* Implemented `find()`, `contains()`, and `search()` methods using linear traversal.
* Implemented `clear()` to delete all nodes and release memory.
* Implemented the destructor using `clear()`.
* Implemented the copy constructor for deep copying.
* Implemented the copy assignment operator for safe object assignment.
* Added index validation and error handling for invalid operations.
* Tested all operations using integer and string data types.

## Problem Encountered

Managing dynamic memory safely during deletion and copying operations required careful pointer handling. Special attention was needed when deleting the last remaining node and when copying linked lists to ensure independent memory allocation.

## What I Tried

* Tested insertion and deletion at different positions.
* Verified correct updates of `head` and `tail` pointers.
* Tested copy constructor and assignment operator using separate LinkedList objects.
* Confirmed that modifications to copied lists did not affect the original list.
* Tested error handling for invalid indices and operations on empty lists.
* Performed testing using both `int` and `string` data types.

## Outcome

Successfully completed all LinkedList operations and verified correct behavior through extensive testing. Deep-copy functionality works correctly, memory is released properly, and the template implementation supports multiple data types.

## Build Status

* Compilation Successful
* deleteFront() implemented
* deleteBack() implemented
* insert(index) implemented
* remove(index) implemented
* get() and set() implemented
* find(), contains(), and search() implemented
* clear() and destructor implemented
* Copy constructor implemented
* Copy assignment operator implemented
* Error handling verified
* Integer and string testing completed
* LinkedList implementation completed successfully

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