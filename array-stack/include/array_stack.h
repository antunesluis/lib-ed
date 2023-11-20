#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <stdbool.h>

typedef struct _static_stack StaticStack;

StaticStack* StaticStack_create(size_t capacity);
void StaticStack_destroy(StaticStack** S_ref);

bool StaticStack_is_empty(const StaticStack* S);
bool StaticStack_is_full(const StaticStack* S);

void StaticStack_push(StaticStack* S, int val);
void StaticStack_peek(const StaticStack* S);
void StaticStack_pop(StaticStack* S);

#endif