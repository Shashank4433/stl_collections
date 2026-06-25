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
