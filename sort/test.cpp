//
// Created by sky on 2023/6/8.
//

#include "select_sort.h"
#include "gtest/gtest.h"

TEST(FactorialTest, Negative) {
    // This test is named "Negative", and belongs to the "FactorialTest"
    // test case.
    int numbers[] = {5, 7, 9, 1, 3, 8, 10, 11, 7};
    int numbers_expected[] = {1, 3, 5, 7, 7, 8, 9, 10, 11};
    unsigned int numbers_cnt = sizeof(numbers) / sizeof(numbers[0]);
    select_sort(numbers, numbers_cnt);
    for(int i=0;i<numbers_cnt;i++) {
        EXPECT_EQ(numbers[i], numbers_expected[i]);
    }
}
