//
// Created by sky on 2023/6/8.
//

#include "select_sort.h"
#include "insert_sort.h"

#include <gtest/gtest.h>

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

TEST(sort, select_sort) {
    srand(time(NULL));
    const unsigned int cnt = 200000;

    int numbers[cnt];
    int numbers_expected[cnt];

    for(int i=1;i<=cnt;i++) {
        numbers[i-1] = i;
        numbers_expected[i-1] = i;
    }

    int ri;
    for(int i=0;i<cnt;i++) {
        ri = rand() % cnt;
        std::swap(numbers[0], numbers[ri]);
    }

    for(int i=0;i<100;i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    select_sort(numbers, cnt);
    for(int i=0;i<cnt;i++) {
        EXPECT_EQ(numbers[i], numbers_expected[i]);
    }
}

TEST(sort, insert_sort) {
    srand(time(NULL));
    const unsigned int cnt = 400000;

    int numbers[cnt];
    int numbers_expected[cnt];

    for(int i=1;i<=cnt;i++) {
        numbers[i-1] = i;
        numbers_expected[i-1] = i;
    }

    int ri;
    for(int i=0;i<cnt;i++) {
        ri = rand() % cnt;
        std::swap(numbers[0], numbers[ri]);
    }

    for(int i=0;i<100;i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    insert_sort(numbers, cnt);

    for(int i=0;i<cnt;i++) {
        EXPECT_EQ(numbers[i], numbers_expected[i]);
    }
}
