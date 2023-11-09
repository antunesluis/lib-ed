#ifndef CIRC_LIST_H
#define CIRC_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct _circ_node CircNode;
typedef struct _circ_list CircList;

CircNode* CircNode_crete(int val);
void CircNode_destroy(CircNode** cnode_ref);

CircList* List_create();
void CircList_destroy(CircList** L_ref);
bool CircList_is_empty(const CircList* L);

#endif