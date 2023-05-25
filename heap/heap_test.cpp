//
// Created by sky on 2023/5/25.
//

#include <iostream>

#include "heap_test.h"
#include "heap.h"

using std::cout;
using std::endl;

void testMaxHeap() {
    MaxHeap maxHeap;

    for (auto i = 90; i < 100; i++) {
        maxHeap.add(i);
    }
    dumpHeap(maxHeap);

    for (auto i = 0; i < 100; i++) {
        maxHeap.add(i);
        maxHeap.get();
    }

    while (maxHeap.getSize() > 0) {
        cout << maxHeap.get() << endl;
    }

    MinHeap minHeap;
    for (auto i = 9; i >= 0; --i) {
        minHeap.add(i);
    }
    dumpHeap(minHeap);

    for (auto i = 0; i <= 100000; ++i) {
        minHeap.add(i);
        minHeap.get();
    }

    while (minHeap.getSize() > 0) {
        cout << minHeap.get() << endl;
    }
}