cmake_minimum_required(VERSION 3.23)

include("cmake/HunterGate.cmake")
HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.24.17.tar.gz"
        SHA1 "e6396699e414120e32557fe92db097b7655b760b"
)

project(data_structures)

set(CMAKE_CXX_STANDARD 20)

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

add_executable(data_structures main.cpp heap/heap.cpp heap/heap.h dump.cpp dump.h heap/heap_test.cpp heap/heap_test.h tree/bin_search_tree.cpp tree/bin_search_tree.h tree/bin_search_tree_test.cpp tree/bin_search_tree_test.h tree/bst_node.cpp tree/bst_node.h)

add_subdirectory(sort)

target_link_libraries(data_structures PUBLIC sort)

