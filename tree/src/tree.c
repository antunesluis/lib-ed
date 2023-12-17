#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* right;
    struct TreeNode* left;
} TreeNode;

int tree_node_get_value(TreeNode* node) {
    if (node) {
        return node->value;
    }
    return -1;
}

void tree_print_in_order(TreeNode* root) {
    if (root) {
        tree_print_in_order(root->left);
        printf("%d ", root->value);
        tree_print_in_order(root->right);
    }
}

void tree_print_pre_order(TreeNode* root) {
    if (root) {
        printf("%d ", root->value);
        tree_print_pre_order(root->left);
        tree_print_pre_order(root->right);
    }
}

TreeNode* tree_insert_node(TreeNode* root, int value) {
    if (!root) {
        TreeNode* new_node = (TreeNode*)calloc(1, sizeof(TreeNode));

        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;

        return new_node;
    }
    else {
        if (value < root->value) {
            root->left = tree_insert_node(root->left, value);
        }
        else {
            root->right = tree_insert_node(root->right, value);
        }

        return root;
    }
}

void tree_insert_node_no_return(TreeNode** root, int value) {
    if (*root == NULL) {
        *root = (TreeNode*)calloc(1, sizeof(TreeNode));
        if (*root == NULL) {
            fprintf(stderr, "Erro na alocação de memória\n");
            exit(EXIT_FAILURE);
        }

        (*root)->value = value;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else {
        if (value < (*root)->value) {
            tree_insert_node_no_return(&((*root)->left), value);
        }
        else {
            tree_insert_node_no_return(&((*root)->right), value);
        }
    }
}

void tree_insert_node_no_return_iterative(TreeNode** root_ref, int value) {
    TreeNode* root = *root_ref;

    while (root) {
        if (value < root->value) {
            root_ref = &root->left;
        }
        else {
            root_ref = &root->right;
        }
        root = *root_ref;
    }

    root = (TreeNode*)calloc(1, sizeof(TreeNode));
    root->value = value;
    root->right = NULL;
    root->left = NULL;

    *root_ref = root;
}

TreeNode* tree_search_node(TreeNode* root, int value) {
    if (root) {
        if (value == root->value) {
            return root;
        }
        else if (value < root->value) {
            return tree_search_node(root->left, value);
        }
        else {
            return tree_search_node(root->right, value);
        }
    }

    return NULL;
}

TreeNode* tree_search_node_iterative(TreeNode* root, int value) {
    while (root) {
        if (value < root->value) {
            root = root->left;
        }
        else if (value > root->value) {
            root = root->right;
        }
        else {
            return root;
        }
    }
    return NULL;
}

int tree_get_height(TreeNode* root) {
    if (!root) {
        return -1;
    }
    else {
        int left = tree_get_height(root->left);
        int right = tree_get_height(root->right);

        return (left > right) ? (left + 1) : (right + 1);
    }
}

int tree_get_node_count(TreeNode* root) {
    return (!root) ? 0 : 1 + tree_get_node_count(root->left) + tree_get_node_count(root->right);
}

int tree_get_leaf_count(TreeNode* root) {
    if (!root) {
        return 0;
    }
    else if (!root->left && !root->right) {
        return 1;
    }
    else {
        return tree_get_leaf_count(root->left) + tree_get_leaf_count(root->right);
    }
}

TreeNode* tree_remove_node(TreeNode* root, int value) {
    // Caso base: se a árvore está vazia ou o valor não está presente
    if (root == NULL) {
        printf("\nValor não encontrado\n");
        return NULL;
    }
    else {
        // Se encontrarmos o nó a ser removido
        if (root->value == value) {
            // Caso 1: O nó a ser removido é uma folha (não tem filhos)
            if (root->left == NULL && root->right == NULL) {
                free(root);
                return NULL;
            }
            else {
                // Caso 2: O nó a ser removido tem dois filhos
                if (root->left != NULL && root->right != NULL) {
                    // Encontrar o nó mais à direita na subárvore esquerda
                    TreeNode* aux = root->left;
                    while (aux->right != NULL) {
                        aux = aux->right;
                    }

                    // Trocar os valores entre o nó a ser removido e o nó mais à direita
                    root->value = aux->value;
                    aux->value = value;

                    // Remover o nó duplicado na subárvore esquerda
                    root->left = tree_remove_node(root->left, value);

                    return root;
                }
                else {
                    // Caso 3: O nó a ser removido tem apenas um filho
                    TreeNode* aux;
                    if (root->left != NULL) {
                        aux = root->left;
                    }
                    else {
                        aux = root->right;
                    }
                    free(root);

                    return aux;
                }
            }
        }
        else {
            // Caso geral: continuar a busca na subárvore correta
            if (value < root->value) {
                root->left = tree_remove_node(root->left, value);
            }
            else {
                root->right = tree_remove_node(root->right, value);
            }
            return root;
        }
    }
}