#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stdio.h>
#include<stddef.h>

typedef struct _snode SNode;
typedef struct _linked_list LinkedList;

SNode* SNode_create(int val);

LinkedList* LinkedList_create();
void LinkedList_destroy(LinkedList** L_ref);
bool LinkedList_is_empty(const LinkedList* L);
void LinkedList_add_first(LinkedList* L, int val);
void LinkedList_add_last(LinkedList* L, int val);
void LinkedList_remove(LinkedList* L, int val);
void LinkedList_print(const LinkedList* L);
size_t LinkedList_size(const LinkedList* L);


int LinkedList_first_val(const LinkedList* L);
int LinkedList_last_val(const LinkedList* L);
int LinkedList_get_val(const LinkedList* L, int index);

#endif