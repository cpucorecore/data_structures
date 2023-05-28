//
// Created by sky on 2023/5/28.
//

#ifndef DATA_STRUCTURES_BST_NODE_H
#define DATA_STRUCTURES_BST_NODE_H


struct bst_node {
    bst_node(int key) : key(key), left(nullptr), right(nullptr) {}

    void add(int key);
    bool del(int key);

    int key;
    bst_node *left;
    bst_node *right;
};


#endif //DATA_STRUCTURES_BST_NODE_H
