//
// Created by sky on 2023/5/25.
//

#ifndef DATA_STRUCTURES_BIN_SEARCH_TREE_H
#define DATA_STRUCTURES_BIN_SEARCH_TREE_H


class bin_search_tree {
public:
    explicit bin_search_tree(int value) : _value(value), left(nullptr), right(nullptr) {}
    virtual void add(int value);
    virtual bool del(int value);

    friend void dump_bin_search_tree(const bin_search_tree &tree);

protected:
    int _value;
    bin_search_tree *left;
    bin_search_tree *right;
};


#endif //DATA_STRUCTURES_BIN_SEARCH_TREE_H
