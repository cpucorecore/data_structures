//
// Created by sky on 2023/5/25.
//

#include "bin_search_tree_test.h"
#include "bin_search_tree.h"

void test_bin_search_tree() {
    bin_search_tree tree = bin_search_tree(10);
    tree.add(5);
    tree.add(8);
    tree.add(15);
    tree.add(4);
    tree.add(16);
    tree.add(14);
    dump_bin_search_tree(tree);

//    tree.del(15);
//    dump_bin_search_tree(tree);
}