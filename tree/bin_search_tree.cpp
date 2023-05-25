//
// Created by sky on 2023/5/25.
//

#include "bin_search_tree.h"

#include <cstring>

void bin_search_tree::add(int value) {
    if(value <= _value) {
        if(left) {
            left->add(value);
        } else {
            left = new bin_search_tree(value);
        }
    } else {
        if(right) {
            right->add(value);
        } else {
            right = new bin_search_tree(value);
        }
    }
}

bool bin_search_tree::del(int value) {
    if(value == _value) {
        if(left && right) {
        } else if(left) {
            memcpy(this, left, sizeof(bin_search_tree));
            delete left;
        } else if(right) {
            memcpy(this, right, sizeof(bin_search_tree));
            delete right;
        } else {
            delete this; // TODO
        }
        return true;
    } else if (value < _value) {
        if(left) {
            return left->del(value);
        }
        return false;
    } else {
        if(right) {
            return right->del(value);
        }
        return false;
    }
}