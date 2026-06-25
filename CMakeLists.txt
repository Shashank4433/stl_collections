cmake_minimum_required(VERSION 3.10)

project(STL_Collections)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    DynamicArrayDemo
    DynamicArray/main.cpp
)

add_executable(
    LinkedListDemo
    LinkedList/main.cpp
)

add_executable(
    HashMapDemo
    HashMap/main.cpp
)
