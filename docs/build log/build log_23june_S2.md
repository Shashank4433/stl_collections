**Session:** 2

**Date:** 23-06-2026

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
