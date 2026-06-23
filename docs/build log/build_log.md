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
