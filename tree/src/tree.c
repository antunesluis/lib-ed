#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* right;
    struct TreeNode* left;
} TreeNode;

void print_in_order(TreeNode* root) {
    if (root) {
        print_in_order(root->left);
        printf("%d ", root->value);
        print_in_order(root->right);
    }
}

void print_pre_order(TreeNode* root) {
    if (root) {
        printf("%d ", root->value);
        print_pre_order(root->left);
        print_pre_order(root->right);
    }
}

TreeNode* insert_tree_node(TreeNode* root, int value) {
    if (root == NULL) {
        TreeNode* new_node = (TreeNode*)calloc(1, sizeof(TreeNode));
        if (new_node == NULL) {
            fprintf(stderr, "Erro na alocação de memória\n");
            exit(EXIT_FAILURE);
        }

        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;

        return new_node;
    }
    else {
        if (value < root->value) {
            root->left = insert_tree_node(root->left, value);
        }
        else {
            root->right = insert_tree_node(root->right, value);
        }

        return root;
    }
}

void insert_tree_node_no_return(TreeNode** root, int value) {
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
            insert_tree_node_no_return(&((*root)->left), value);
        }
        else {
            insert_tree_node_no_return(&((*root)->right), value);
        }
    }
}

void insert_tree_node_no_return_and_iteration(TreeNode** root_ref, int value) {
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