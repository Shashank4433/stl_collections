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
