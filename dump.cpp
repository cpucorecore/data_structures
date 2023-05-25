//
// Created by sky on 2023/5/25.
//

#include <vector>
#include <iostream>

#include "dump.h"

using std::vector;
using std::cout;
using std::endl;

vector<size_t> getChildIndexes(size_t maxIndex, vector<size_t> &rootIndexes) {
    vector<size_t> ret;

    size_t l, r;
    for(auto rootIndex : rootIndexes) {
        l = rootIndex*2+1;
        r = rootIndex*2+2;

        if(l <= maxIndex)
            ret.push_back(l);

        if(r <= maxIndex)
            ret.push_back(r);
    }

    return ret;
}

void dumpBinaryTree(const Heap &h) {
    size_t size = h.getSize();
    if(size == 0) return;

    size_t maxIndex = size - 1;
    cout << "[" << endl;

    vector<size_t> rootNodeIndexes{0};
    vector<size_t> childNodeIndexes = getChildIndexes(maxIndex, rootNodeIndexes);
    while(rootNodeIndexes.size() > 0) {
        for(auto index : rootNodeIndexes) {
            cout << h.data[index] << " ";
        }
        cout << endl;
        rootNodeIndexes = childNodeIndexes;
        childNodeIndexes = getChildIndexes(maxIndex, rootNodeIndexes);
    }

    cout << "]" << endl << endl;
}