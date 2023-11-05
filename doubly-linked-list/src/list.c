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
    if (List_is_empty(L)) {
        return;
    }

    Node* p = L->begin;

    // caso 1: o elemento está na cabeça da lista
    if (L->begin->val == val) {
        L->begin = p->next;

        // a lista possui apenas um único elemento
        if (L->end == p) {
            L->end = NULL;
        }
        // a lista possui mais de um elemento
        else {
            L->begin->prev = NULL;
        }

        free(p);
        L->size--;
    }
    else {
        p = p->next;

        while (p != NULL) {
            if (p->val == val) {
                p->prev->next = p->next;

                // caso 3: o elemento está no final da lista
                if (L->end == p) {
                    L->end = p->prev;
                }
                // caso 2: o elemento está no meio da lista
                else {
                    p->next->prev = p->prev;
                }

                free(p);
                p = NULL;
                L->size--;
            }
            else {
                p = p->next;
            }
        }
    }
}

size_t List_size(const List* L) {
    if (List_is_empty(L)) {
        fprintf(stderr, "ERROR in 'List_size'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    return L->size;
}

int List_first_val(const List* L) {
    if (List_is_empty(L)) {
        fprintf(stderr, "ERROR in 'List_first_val'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    return L->begin->val;
}

int List_last_val(const List* L) {
    if (List_is_empty(L)) {
        fprintf(stderr, "ERROR in 'List_last_val'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    return L->end->val;
}

int List_get_val(const List* L, int index) {
    if (List_is_empty(L)) {
        fprintf(stderr, "ERROR in 'List_get_val'\n");
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }

    if (index < 0 || index >= L->size) {
        fprintf(stderr, "ERROR in 'List_get_val'\n");
        fprintf(stderr, "invalid index: %d\n", index);
        fprintf(stderr, "Try an index within [0, %lu]\n", L->size - 1);
        exit(EXIT_FAILURE);
    }

    Node* p = L->begin;
    for (int i = 0; i != index; i++) {
        p = p->next;
    }

    return p->val;
}