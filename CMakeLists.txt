cmake_minimum_required(VERSION 3.23)
project(data_structures)

set(CMAKE_CXX_STANDARD 20)

add_executable(data_structures main.cpp heap/heap.cpp heap/heap.h dump.cpp dump.h heap/heap_test.cpp heap/heap_test.h)
