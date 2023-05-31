//
// Created by sky on 2023/5/28.
//

#include "bin_search_tree.h"

void bin_search_tree::add(int key) {
    if(nullptr == root) {
        root = new bst_node(key);
        return;
    }

    root->add(key);
}

bool bin_search_tree::del(int key) {
    if(nullptr == root) return false;
    if(nullptr == root->left && nullptr == root->right) {
//todo compare keys and judge if or not to del
        delete root;
        root = nullptr;
        return true;
    }

    return root->del(key);
}