//
// Created by sky on 2023/5/28.
//

#include "bst_node.h"

void bst_node::add(int key) {
    if(key <= this->key) {
        if(left) {
            return left->add(key);
        }
        left = new bst_node(key);
    } else {
        if(right) {
            return right->add(key);
        }
        right = new bst_node(key);
    }
}

bool bst_node::del(int key) {
    if(key == this->key) {
        bst_node *candidate_root = this;
        bst_node *candidate = nullptr;

        if(left) {
            candidate = left;
            while(candidate->right) {
                candidate_root = candidate;
                candidate = candidate_root->right;
            }
            this->key = candidate->key;
            if(candidate == left) {
                left = left->left;
            } else {
                candidate_root->right = candidate->left;
            }
            delete candidate;
            return true;
        }

        if(right) {
            candidate = right;
            while(candidate->left) {
                candidate_root = candidate;
                candidate = candidate_root->left;
            }
            this->key = candidate->key;
            if(candidate == right) {
                right = right->right;
            } else {
                candidate_root->left = candidate->right;
            }
            delete candidate;
            return true;
        }
    } else if(key < this->key) {
        if(left) {
            if(nullptr == left->left && nullptr == left->right) { //left is leaf node
                if(left->key == key) {
                    delete left;
                    left = nullptr;
                    return true;
                }
                return false;
            }
            return left->del(key);
        }
        return false;
    } else {
        if(right) {
            if(nullptr == right->left && nullptr == right->right) { //right is leaf node
                if(right->key == key) {
                    delete right;
                    right = nullptr;
                    return true;
                }
                return false;
            }
            return right->del(key);
        }
        return false;
    }
}
