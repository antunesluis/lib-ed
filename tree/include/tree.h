#ifndef TREE_H
#define TREE_H

#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode TreeNode;

int tree_node_get_value(TreeNode* node);

void tree_print_in_order(TreeNode* root);

void tree_print_pre_order(TreeNode* root);

TreeNode* tree_insert_node(TreeNode* root, int value);

void tree_insert_node_no_return(TreeNode** root, int value);

void tree_insert_node_no_return_iterative(TreeNode** root_ref, int value);

TreeNode* tree_search_node(TreeNode* root, int value);

TreeNode* tree_search_node_iterative(TreeNode* root, int value);

int tree_get_height(TreeNode* root);

int tree_get_node_count(TreeNode* root);

int tree_get_leaf_count(TreeNode* root);

TreeNode* tree_remove_node(TreeNode* root, int value);

#endif