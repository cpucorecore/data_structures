//
// Created by sky on 2023/5/28.
//

#ifndef DATA_STRUCTURES_BIN_SEARCH_TREE_H
#define DATA_STRUCTURES_BIN_SEARCH_TREE_H


#include "bst_node.h"

class bin_search_tree {
public:
    bin_search_tree() = default;

    virtual void add(int key);
    virtual bool del(int key);


    friend void dump_bin_search_tree(const bin_search_tree &tree);

protected:
    bst_node *root;
};


#endif //DATA_STRUCTURES_BIN_SEARCH_TREE_H
