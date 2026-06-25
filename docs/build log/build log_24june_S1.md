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
