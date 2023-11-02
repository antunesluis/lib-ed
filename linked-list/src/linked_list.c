#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _snode {
    int val;
    struct _snode* next;
} SNode;


typedef struct _linked_list {
    SNode* begin;
    SNode* end;
    size_t size;
} LinkedList;


SNode* SNode_create(int val) {
    SNode* snode = (SNode*)calloc(1, sizeof(SNode));
    snode->val = val;
    snode->next = NULL;

    return snode;
}

LinkedList* LinkedList_create() {
    LinkedList* L = (LinkedList*)calloc(1, sizeof(LinkedList));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}

bool LinkedList_is_empty(const LinkedList* L) {
    return (L->size == 0);
}

void LinkedList_add_first(LinkedList* L, int val) {
    SNode* p = SNode_create(val);
    p->next = L->begin;

    if (LinkedList_is_empty(L)) {
        L->end = p;
    }

    L->begin = p;
    L->size++;
}

void LinkedList_add_last(LinkedList* L, int val) {
    SNode* q = SNode_create(val);

    if (LinkedList_is_empty(L)) {
        L->begin = q;
        L->end = q;
    }
    else {
        L->end->next = q;
        L->end = L->end->next;
    }
    L->size++;
}

void LinkedList_remove(LinkedList* L, int val) {
    if (!LinkedList_is_empty(L)) {
        SNode* prev = NULL;
        SNode* pos = L->begin;

        while (pos != NULL && pos->val != val) {
            prev = pos;
            pos = pos->next;
        }

        // se achou um nó com valor val
        if (pos != NULL) {
            if (L->end == pos) {
                L->end = prev;
            }

            if (L->begin == pos) {
                L->begin = L->begin->next;
            }
            // o nó pós está no meio da lista
            else {
                prev->next = pos->next;
            }

            free(pos);
            L->size--;
        }
    }
}

void LinkedList_destroy(LinkedList** L_ref) {
    LinkedList* L = *L_ref;

    SNode* p = L->begin;
    SNode* aux = NULL;

    while (p != NULL) {
        aux = p;
        p = p->next;
        free(aux);
    }
    free(L);

    *L_ref = NULL;
}

void LinkedList_print(const LinkedList* L) {
    SNode* p = L->begin;

    printf("\nSize: %lu\n", L->size);
    printf("L -> ");

    while (p != NULL) {
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");

    if (L->end == NULL) {
        printf("L->end = NULL\n");
    }
    else {
        printf("L->end = %d\n", L->end->val);
    }
}

size_t LinkedList_size(const LinkedList* L) {
    return L->size;
}

int LinkedList_first_val(const LinkedList* L) {
    if (LinkedList_is_empty(L)) {
        fprintf(stderr, "ERROR in 'LinkedList_first_val'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    return L->begin->val;
}

int LinkedList_last_val(const LinkedList* L) {
    if (LinkedList_is_empty(L)) {
        fprintf(stderr, "ERROR in 'LinkedList_last_val'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    return L->end->val;
}

int LinkedList_get_val(const LinkedList* L, int index) {
    if (LinkedList_is_empty(L)) {
        fprintf(stderr, "ERROR in 'LinkedList_get_val'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }

    if (index < 0 || index >= L->size) {
        fprintf(stderr, "ERROR in 'LinkedList_get_val'\n");
        fprintf(stderr, "invalid index: %d\n", index);
        fprintf(stderr, "Try an index within [0, %lu]\n", L->size - 1);
        exit(EXIT_FAILURE);
    }

    SNode* p = L->begin;
    for (int i = 0; i != index; i++) {
        p = p->next;
    }

    return p->val;
}
