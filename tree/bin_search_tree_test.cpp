//
// Created by sky on 2023/5/28.
//

#include "bin_search_tree_test.h"
#include "bin_search_tree.h"

void test_bin_search_tree() {
    bin_search_tree tree = bin_search_tree();
    tree.add(5);
    tree.add(8);
    tree.add(15);
    tree.add(4);
    tree.add(16);
    tree.add(14);
    tree.add(7);
    dump_bin_search_tree(tree);

    tree.del(8);
    dump_bin_search_tree(tree);

    tree.del(7);
    dump_bin_search_tree(tree);

    tree.del(5);
    dump_bin_search_tree(tree);

    tree.del(14);
    dump_bin_search_tree(tree);

    bin_search_tree tree2 = bin_search_tree();
    tree2.add(100);
    tree2.add(90);
    tree2.add(110);
    tree2.add(95);
    tree2.add(85);
    tree2.add(80);
    tree2.add(87);
    dump_bin_search_tree(tree2);

    tree2.del(90);
    dump_bin_search_tree(tree2);

    tree2.del(95);
    dump_bin_search_tree(tree2);

    tree2.del(100);
    dump_bin_search_tree(tree2);

    tree2.del(85);
    dump_bin_search_tree(tree2);

    tree2.del(87);
    dump_bin_search_tree(tree2);

    tree2.del(80);
    dump_bin_search_tree(tree2);

    tree2.del(80);
    dump_bin_search_tree(tree2);

    tree2.del(110);
    dump_bin_search_tree(tree2);
}