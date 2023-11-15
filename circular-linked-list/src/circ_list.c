#include "circ_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> 

typedef struct _circ_node {
    int val;
    struct _circ_node* prev;
    struct _circ_node* next;
} CircNode;

typedef struct _circ_list {
    CircNode* begin;
    CircNode* end;
    size_t size;
} CircList;

CircNode* CircNode_crete(int val) {
    CircNode* cnode = (CircNode*)calloc(1, sizeof(CircNode));
    cnode->val = val;
    cnode->prev = cnode;
    cnode->next = cnode;

    return cnode;
}

void CircNode_destroy(CircNode** cnode_ref) {
    CircNode* cnode = *cnode_ref;
    free(cnode);
    *cnode_ref = NULL;
}

CircList* CircList_create() {
    CircList* L = (CircList*)calloc(1, sizeof(CircList));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}

void CircList_destroy(CircList** L_ref) {
    CircList* L = *L_ref;

    CircNode* p = L->begin;
    CircNode* aux = NULL;

    while (p != L->end) {
        aux = p;
        p = p->next;
        CircNode_destroy(&aux);
    }
    CircNode_destroy(&p);
    free(L);

    *L_ref = NULL;
}

void CircList_destroy_v2(CircList** L_ref) {
    CircList* L = *L_ref;

    CircNode* p = L->begin;
    CircNode* aux = NULL;

    for (int i = 0; i < L->size; i++) {
        aux = p;
        p = p->next;
        CircNode_destroy(&aux);
    }
    free(L);
    *L_ref = NULL;
}

bool CircList_is_empty(const CircList* L) {
    return L->size == 0;
}

void CircList_add_first(CircList* L, int val) {
    CircNode* p = CircNode_crete(val);

    if (CircList_is_empty(L)) {
        L->end = p;
    }
    else {
        p->next = L->begin;
        L->begin->prev = p;
        p->prev = L->end;
        L->end->next = p;
    }

    L->begin = p;
    L->size++;
}

void CircList_add_last(CircList* L, int val) {
    CircNode* p = CircNode_crete(val);

    if (CircList_is_empty(L)) {
        L->begin = p;
    }
    else {
        L->end->next = p;
        p->prev = L->end;

        //parte circular
        L->begin->prev = p;
        p->next = L->begin;
    }

    L->end = p;
    L->size++;
}

void CircList_print(const CircList* L) {
    printf("\nsize: %lu\n", L->size);

    if (CircList_is_empty(L)) {
        printf("L-> NULL\n");
        printf("L->end -> NULL\n");
        return;
    }

    CircNode* p = L->begin;

    printf("L -> ");
    do {
        printf("%d -> ", p->val);
        p = p->next;
    } while (p != L->begin);

    printf("\nL->end -> %d\n", L->end->val);

}

void CircList_print_v2(const CircList* L) {
    printf("\nsize: %lu\n", L->size);

    if (CircList_is_empty(L)) {
        printf("L-> NULL\n");
        printf("L->end -> NULL\n");
        return;
    }

    CircNode* p = L->begin;
    printf("L -> ");

    for (int i = 0; i < L->size; i++) {
        printf("%d -> ", p->val);
        p = p->next;
    }

    printf("\nL->end -> %d\n", L->end->val);

}

void CircList_inverted_print(const CircList* L) {
    printf("\nsize: %lu\n", L->size);

    if (CircList_is_empty(L)) {
        printf("L-> NULL\n");
        printf("L->end -> NULL\n");
        return;
    }

    CircNode* p = L->end;

    printf("L -> ");
    do {
        printf("%d -> ", p->val);
        p = p->prev;
    } while (p != L->end);

    printf("\nL->end -> %d\n", L->end->val);
}

void CircList_inverted_print_v2(const CircList* L) {
    printf("\nsize: %lu\n", L->size);

    if (CircList_is_empty(L)) {
        printf("L-> NULL\n");
        printf("L->end -> NULL\n");
        return;
    }

    CircNode* p = L->end;
    printf("L -> ");

    for (int i = 0; i < L->size; i++) {
        printf("%d -> ", p->val);
        p = p->prev;
    }

    printf("\nL->end -> %d\n", L->end->val);
}

void CircList_remove(CircList* L, int val) {
    if (!CircList_is_empty(L)) {
        CircNode* p = L->begin;

        // caso 1: o elemento está na cabeça da lista
        if (L->begin->val == val) {
            // a lista possui um único elemento
            if (L->begin == L->end) {
                L->begin = NULL;
                L->end = NULL;
            }
            // a lista possui mais de um elemento
            else {
                L->begin = p->next;
                L->begin->prev = L->end;
                L->end->next = L->begin;
            }

            CircNode_destroy(&p);
            L->size--;
        }
        // caso 2: o elemento está no meio da lista
        // caso 3: o elemento está no final da lista
        else {
            p = p->next;

            while (p != L->begin) {
                if (p->val == val) {
                    // caso 3: o elemento está no final da lista
                    if (L->end == p) {
                        L->end = p->prev;
                    }

                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                    CircNode_destroy(&p);
                    L->size--;
                    break;
                }
                else {
                    p = p->next;
                }
            }
        }
    }
}
