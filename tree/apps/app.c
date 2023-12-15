#include "tree.h"
#include <stdio.h>

int main() {
    Node* root = NULL;

    root = tree_add_v1(root, 50);
    root = tree_add_v1(root, 100);
    root = tree_add_v1(root, 200);
    root = tree_add_v1(root, 125);
    root = tree_add_v1(root, 25);
    root = tree_add_v1(root, 95);

    tree_print_v2(root);

    return 0;
}