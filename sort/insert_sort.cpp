//
// Created by sky on 2023/6/8.
//

#include "insert_sort.h"

void insert_sort(int numbers[], unsigned int n) {
    for(int i=1;i<n;i++) {
        if(numbers[i] >= numbers[i-1]) continue;

        int s = 0, e = i, m = (s + e) / 2;
        while(e - s > 1) {
            if(numbers[i] == numbers[m]) {
                break;
            } else if(numbers[i] > numbers[m]) {
                s = m;
                m = (s+e)/2;
            } else {
                e = m;
                m = (s+e)/2;
            }
        }
        if(numbers[i] >= numbers[m]) {
            m = m+1;
        }
        int t = numbers[i];
        for(int j=i;j>=m;j--) {
            numbers[j] = numbers[j-1];
        }
        numbers[m] = t;
    }
}