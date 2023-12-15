#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _node {
    int val;
    struct _node* right;
    struct _node* left;
} Node;

void tree_print_v2(Node* root) {
    if (root) {
        tree_print_v2(root->left);
        printf("%d ", root->val);
        tree_print_v2(root->right);
    }
}

void tree_print_v1(Node* root) {
    if (root) {
        printf("%d ", root->val);
        tree_print_v1(root->left);
        tree_print_v1(root->right);
    }
}

Node* tree_add_v1(Node* root, int val) {
    if (root == NULL) {
        Node* aux = (Node*)calloc(1, sizeof(Node));

        aux->val = val;
        aux->left = NULL;
        aux->right = NULL;

        return aux;
    }
    else {
        if (val < root->val) {
            root->left = tree_add_v1(root->left, val);
        }
        else {
            root->right = tree_add_v1(root->right, val);
        }

        return root;
    }
}

void tree_add_no_return(Node** root, int val) {
    if (root == NULL) {
        *root = (Node*)calloc(1, sizeof(Node));

        (*root)->val = val;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else {
        if (val < (*root)->val) {
            tree_add_no_return(&((*root)->left), val);
        }
        else {
            tree_add_no_return(&((*root)->right), val);
        }
    }
}

void tree_add_no_return_and_recursion(Node** root_ref, int val) {
    Node* root = *root_ref;

    while (root) {

    }

    root = (Node*)calloc(1, sizeof(Node));
    root->val = val;
    root->right = NULL;
    root->left = NULL;

    *root_ref = root;
}