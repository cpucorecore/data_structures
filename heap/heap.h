//
// Created by sky on 2023/5/23.
//

#ifndef DATA_STRUCTURES_HEAP_H
#define DATA_STRUCTURES_HEAP_H

#include <vector>

const int MAX_SIZE = 100;

struct Heap {
public:
    virtual int get() = 0;
    virtual void add(int v) = 0;

    size_t getSize() const {
        return size;
    }

    friend void dumpBinaryTree(const Heap &h);

protected:
    int size = 0;
    int data[MAX_SIZE];
};

struct MaxHeap : public Heap {
    void add(int v) override;
    int get() override;
};

struct MinHeap : public Heap {
    void add(int v) override;
    int get() override;
};


#endif //DATA_STRUCTURES_HEAP_H
