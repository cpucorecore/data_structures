//
// Created by sky on 2023/5/23.
//

#include "heap.h"

size_t calcRootIndex(size_t childIndex) {
    if(childIndex == 0) return 0;
    return (childIndex - 1) / 2;
}

void MaxHeap::add(int v) {
    if(size >= MAX_SIZE) {
        throw std::exception();
    }

    data[size] = v;
    ++size;

    if(size == 1) return;

    size_t childIndex = size - 1;
    size_t rootIndex = calcRootIndex(childIndex);
    while(childIndex != rootIndex) {
        if (data[childIndex] > data[rootIndex]) {
            std::swap(data[childIndex], data[rootIndex]);
            childIndex = rootIndex;
            rootIndex = calcRootIndex(childIndex);
        } else {
            break;
        }
    }
}

int MaxHeap::get() {
    if(size == 0) {
        throw std::exception();
    }

    if(size == 1) {
        --size;
        return data[0];
    }

    int v = data[0];
    data[0] = data[size - 1];

    --size;

    if(size <= 1) return v;
    if(size == 2) {
        if(data[0] < data[1]) {
            std::swap(data[0], data[1]);
            return v;
        }

        return v;
    }

    size_t rootIndex = 0;
    size_t childLeftIndex = rootIndex * 2 + 1;
    size_t childRightIndex = rootIndex * 2 + 2;
    size_t childBiggerIndex = data[childLeftIndex] > data[childRightIndex] ? childLeftIndex : childRightIndex;

    while(childBiggerIndex < size) {
        if(data[rootIndex] < data[childBiggerIndex]) {
            std::swap(data[rootIndex], data[childBiggerIndex]);
        } else {
            break;
        }

        rootIndex = childBiggerIndex;
        childLeftIndex = rootIndex * 2 + 1;
        childRightIndex = rootIndex * 2 + 2;

        if (childLeftIndex < size && childRightIndex < size) {
            childBiggerIndex = data[childLeftIndex] > data[childRightIndex] ? childLeftIndex : childRightIndex;
        } else if (childLeftIndex < size) {
            childBiggerIndex = childLeftIndex;
        } else if (childRightIndex < size) {
            childBiggerIndex = childRightIndex;
        } else {
            break;
        }
    }

    return v;
}

void MinHeap::add(int v) {
    if(size >= MAX_SIZE) {
        throw std::exception();
    }

    data[size] = v;
    ++size;

    if(size == 1) return;

    size_t newNodeIndex = size - 1;
    size_t newNodeRootIndex = calcRootIndex(newNodeIndex);
    while(newNodeIndex != newNodeRootIndex) {
        if(data[newNodeIndex] < data[newNodeRootIndex]) {
            std::swap(data[newNodeIndex], data[newNodeRootIndex]);

            newNodeIndex = newNodeRootIndex;
            newNodeRootIndex = calcRootIndex(newNodeIndex);
        } else {
            break;
        }
    }
}

int MinHeap::get() {
    if(size == 0) {
        throw std::exception();
    }

    int ret = data[0];
    data[0] = data[size-1];

    --size;
    if(size <= 1) return ret;
    if(size == 2) {
        if(data[0] > data[1]) {
            std::swap(data[0], data[1]);
        }
        return ret;
    }

    size_t rootIndex = 0;
    size_t childLeftIndex = rootIndex * 2 + 1;
    size_t childRightIndex = rootIndex * 2 + 2;
    size_t smallChildIndex = data[childLeftIndex] <= data[childRightIndex] ? childLeftIndex : childRightIndex;
    while(true) {
        if(data[rootIndex] > data[smallChildIndex]) {
            std::swap(data[rootIndex], data[smallChildIndex]);

            rootIndex = smallChildIndex;
            childLeftIndex = rootIndex * 2 + 1;
            childRightIndex = rootIndex * 2 + 2;

            if(childLeftIndex < size && childRightIndex < size) {
                smallChildIndex = data[childLeftIndex] <= data[childRightIndex] ? childLeftIndex : childRightIndex;
            } else if(childLeftIndex < size) {
                smallChildIndex = childLeftIndex;
            } else if(childRightIndex < size) {
                smallChildIndex = childRightIndex;
            } else {
                break;
            }
        } else {
            break;
        }
    }

    return ret;
}
