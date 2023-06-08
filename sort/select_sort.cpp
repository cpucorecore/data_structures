//
// Created by sky on 2023/6/8.
//

#include "select_sort.h"
#include <algorithm>

void select_sort(int numbers[], unsigned int n) {
    if(n <= 1) return;

    int min_index;
    for(int i=0;i<n-1;i++) {
        min_index = i;
        for(int j=i+1;j<n;j++) {
            if(numbers[j] < numbers[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i)
            std::swap(numbers[min_index], numbers[i]);
    }
}