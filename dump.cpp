//
// Created by sky on 2023/5/25.
//

#include <vector>
#include <deque>
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

void dumpHeap(const Heap &heap) {
    size_t size = heap.getSize();
    if(size == 0) return;

    size_t maxIndex = size - 1;
    cout << "[" << endl;

    vector<size_t> rootNodeIndexes{0};
    vector<size_t> childNodeIndexes = getChildIndexes(maxIndex, rootNodeIndexes);
    while(rootNodeIndexes.size() > 0) {
        for(auto index : rootNodeIndexes) {
            cout << heap.data[index] << " ";
        }
        cout << endl;
        rootNodeIndexes = childNodeIndexes;
        childNodeIndexes = getChildIndexes(maxIndex, rootNodeIndexes);
    }

    cout << "]" << endl << endl;
}

void dump_bin_search_tree(const bin_search_tree &tree) {
    cout << "[" << endl;
    std::deque<const bin_search_tree*> dq{&tree};

    while(!dq.empty()) {
        std::deque<const bin_search_tree*> child;
        for(auto n : dq) {
            if (n) {
                cout << n->_value << " ";
            } else {
                cout << "* ";
                child.push_back(nullptr);
                child.push_back(nullptr);
                continue;
            }

            if(n->left) {
                child.push_back(n->left);
            } else {
                child.push_back(nullptr);
            }

            if(n->right) {
                child.push_back(n->right);
            } else {
                child.push_back(nullptr);
            }
        }
        cout << endl;

        size_t nullCount = 0;
        for(auto n : child) {
            if(!n) {
                nullCount++;
            }
        }
        if(nullCount == child.size()) {
            break;
        }
        dq = child;
    }

    cout << "]" << endl;
}