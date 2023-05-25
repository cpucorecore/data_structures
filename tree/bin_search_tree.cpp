//
// Created by sky on 2023/5/25.
//

#include "bin_search_tree.h"

#include <cstring>

bin_search_tree* bin_search_tree::find(int value) {
    if(value == _value) return this;
    if(value < _value) {
        if(left) {
            return left->find(value);
        }
        return nullptr;
    }
    if(value > _value) {
        if(right) {
            return right->find(value);
        }
        return nullptr;
    }
}

bin_search_tree* bin_search_tree::find_root(int value) {
    if(value < _value) {
        if(left) {
            if(value == left->_value) {
                return this;
            }
            return left->find_root(value);
        }
    } else if(value > _value) {
        if(right) {
            if(value == right->_value) {
                return this;
            }
            return right->find_root(value);
        }
    } else {
        return nullptr;
    }
}

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
    return true;
}