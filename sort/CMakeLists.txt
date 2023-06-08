add_library(sort select_sort.cpp select_sort.h insert_sort.cpp insert_sort.h)

add_executable(sort_test test.cpp)
target_link_libraries(sort_test PRIVATE sort GTest::gtest_main)

add_test(NAME sort_test COMMAND sort_test)