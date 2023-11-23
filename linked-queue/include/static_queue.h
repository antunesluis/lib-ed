#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <stdbool.h>
#include <stddef.h>


typedef struct _static_queue StaticQueue;

StaticQueue* StaticStack_create(long capacity);
void StaticQueue_destroy(StaticQueue** Q_ref);

bool StaticQueue_is_empty(const StaticQueue* Q);
bool StaticQueue_is_full(const StaticQueue* Q);
long StaticQueue_size(const StaticQueue* Q);

void StaticQueue_enqueue(StaticQueue* S, int val);
int StaticQueue_peek(const StaticQueue* S);
int StaticQueue_dequeue(StaticQueue* S);

void StaticQueue_print(const StaticQueue* Q);


#endif