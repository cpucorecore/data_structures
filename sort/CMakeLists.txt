add_library(sort select_sort.cpp select_sort.h)

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

add_executable(sort_test test.cpp)
target_link_libraries(sort_test PRIVATE sort GTest::gtest_main)
