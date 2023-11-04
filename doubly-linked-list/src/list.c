#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> 

typedef struct _doubly_node {
    int val;
    struct _doubly_node* prev;
    struct _doubly_node* next;
} DoublyNode, Node;


typedef struct _doubly_linked_list {
    Node* begin;
    Node* end;
    size_t size;
} DoublyLinkedList, List;


Node* Node_crete(int val) {
    Node* node = (Node*)calloc(1, sizeof(Node));
    node->prev = NULL;
    node->next = NULL;
    node->val = val;

    return node;
}

List* List_create() {
    List* L = (List*)calloc(1, sizeof(List));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}

void List_destroy(List** L_ref) {
    List* L = *L_ref;

    Node* p = L->begin;
    Node* aux = NULL;

    while (p != NULL) {
        aux = p;
        p = p->next;
        free(aux);
    }
    free(L);

    *L_ref = NULL;
}

bool List_is_empty(const List* L) {
    return L->size == 0;
}

void List_add_first(List* L, int val) {
    Node* p = Node_crete(val);
    p->next = L->begin;

    if (List_is_empty(L)) {
        L->end = p;
    }
    else {
        L->begin->prev = p;
    }

    // List_is_empty(L) ? (L->end = p) : (L->begin->prev = p); 
    L->begin = p;
    L->size++;

}

void List_add_last(List* L, int val) {
    Node* p = Node_crete(val);
    p->prev = L->end;

    if (List_is_empty(L)) {
        L->begin = p;
    }
    else {
        L->end->next = p;
    }

    // List_is_empty(L) ? (L->begin = p) : (L->end->prev = p);
    L->end = p;
    L->size++;
}

void List_print(const List* L) {
    Node* p = L->begin;

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
    puts("");
}

void List_inverted_print(const List* L) {
    Node* p = L->end;

    printf("\nSize: %lu\n", L->size);
    printf("L ->end -> ");

    while (p != NULL) {
        printf("%d -> ", p->val);
        p = p->prev;
    }
    printf("NULL\n");

    if (L->end == NULL) {
        printf("L->begin = NULL\n");
    }
    else {
        printf("L->begin = %d\n", L->begin->val);
    }
    puts("");
}

void List_remove(List* L, int val) {
    if (!List_is_empty(L)) {
        // elemento na cabeça da lista
        if (L->begin->val == val) {
            Node* p = L->begin;
            L->begin = p->next;

            // a lista possui apenas um elemento
            if (L->begin == L->end) {
                L->end = NULL;
            }
            else {
                L->begin->prev = NULL;
            }

            free(p);
            L->size--;
        }
        else {
            Node* p = L->begin->next;

            while (p != NULL) {
                if (p->val == val) {

                    // elemento no final da lista
                    if (L->end == p) {

                    }

                    // elemento no meio da lista
                    else {
                        p->prev->next = p->next;
                        p->next->next = p->prev;
                        free(p);
                    }
                }
                else {
                    p = p->next;
                }
            }

        }
    }

}
