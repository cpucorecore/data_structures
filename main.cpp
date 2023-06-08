#include "heap/heap_test.h"
#include "tree/bin_search_tree_test.h"
#include "sort/select_sort.h"

#include <iostream>
using std::cout;
using std::endl;

int main() {
    // testMaxHeap();
    //test_bin_search_tree();
    int numbers[] = {5, 7, 9, 1, 3, 8, 10, 11, 7};
    select_sort(numbers, sizeof(numbers) / sizeof(numbers[0]));
    for(auto n : numbers) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
