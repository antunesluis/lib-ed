#include "tree.h"
#include <stdio.h>

int main() {
    Node* root = NULL;

    tree_add_no_return_and_recursion(&root, 50);
    tree_add_no_return_and_recursion(&root, 100);
    tree_add_no_return_and_recursion(&root, 200);
    tree_add_no_return_and_recursion(&root, 125);
    tree_add_no_return_and_recursion(&root, 25);
    tree_add_no_return_and_recursion(&root, 95);

    tree_print_v2(root);

    return 0;
}