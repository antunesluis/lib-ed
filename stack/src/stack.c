#include "stack.h"
#include "list.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct _stack {
    List* data;
}Stack;

Stack* Stack_create() {
    Stack* S = (Stack*)calloc(1, sizeof(Stack));
    S->data = List_create();

    return S;
}

void Stack_destroy(Stack** S_ref) {
    Stack* S = *S_ref;

    List_destroy(&S->data);
    free(S);
    *S_ref = NULL;
}

bool Stack_is_empty(const Stack* S) {
    return List_is_empty(S->data);
}

void check_empty_stack(const Stack* S, const char* function_name) {
    if (Stack_is_empty(S)) {
        fprintf(stderr, "ERROR in '%s'\n", function_name);
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
}

size_t Stack_size(const Stack* S) {
    return List_size(S->data);
}

void Stack_push(Stack* S, int val) {
    List_add_last(S->data, val);
}

int Stack_peek(const Stack* S) {
    check_empty_stack(S, "Stack_peek");
    return List_get_last_val(S->data);
}

int Stack_pop(Stack* S) {
    check_empty_stack(S, "Stack_pop");

    int val = List_get_last_val(S->data);
    List_remove_last(S->data);

    return val;
}

void Stack_print(const Stack* S) {
    List_print(S->data);
}

