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
