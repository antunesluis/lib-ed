
#include "array_stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct _static_stack {
    int* data;
    size_t capacity;
    int top;
}StaticStack;


StaticStack* StaticStack_create(size_t capacity) {

}

void StaticStack_destroy(StaticStack** S_ref) {

}

bool StaticStack_is_empty(const StaticStack* S) {

}

bool StaticStack_is_full(const StaticStack* S) {

}

void StaticStack_push(StaticStack* S, int val) {

}

void StaticStack_peek(const StaticStack* S) {

}

void StaticStack_pop(StaticStack* S) {

}

#include <stdlib.h>
#include <stdio.h>


