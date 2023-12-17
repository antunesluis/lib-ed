#include "tree.h"
#include <stdio.h>

int main() {
    TreeNode* root = NULL;

    root = tree_insert_node(root, 50);
    root = tree_insert_node(root, 100);
    tree_insert_node_no_return(&root, 200);
    tree_insert_node_no_return(&root, 125);
    tree_insert_node_no_return_iterative(&root, 25);
    tree_insert_node_no_return_iterative(&root, 95);

    tree_print_in_order(root);

    printf("\n\nValor buscado: 200\n");
    TreeNode* node = tree_search_node_iterative(root, 200);
    printf("Valor obtido: %d\n", tree_node_get_value(node));

    printf("\nAltura arvore: %d\n", tree_get_height(root));
    printf("\nNumero de nos: %d\n", tree_get_node_count(root));
    printf("\nNumero de folhas: %d\n", tree_get_leaf_count(root));

    printf("\n\nValor removido: 200\n");
    root = tree_remove_node(root, 200);
    tree_print_in_order(root);

    return 0;
}
