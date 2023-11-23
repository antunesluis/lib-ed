
#include "static_queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct _static_queue {
    int* data;
    long capacity;
    long size;
    long begin;
    long end;
}StaticQueue;

StaticQueue* StaticQueue_create(long capacity) {
    StaticQueue* Q = (StaticQueue*)calloc(1, sizeof(StaticQueue));

    Q->capacity = capacity;
    Q->data = (int*)calloc(capacity, sizeof(int));
    Q->size = 0;
    Q->begin = 0;
    Q->end = 0;

    return Q;
}

void StaticQueue_destroy(StaticQueue** Q_ref) {
    StaticQueue* Q = *Q_ref;

    free(Q->data);
    free(Q);
    *Q_ref = NULL;
}

bool StaticQueue_is_empty(const StaticQueue* Q) {
    return Q->size == 0;
}

bool StaticQueue_is_full(const StaticQueue* Q) {
    return Q->size == Q->capacity;
}

long StaticQueue_size(const StaticQueue* Q) {
    return Q->size;
}

void check_empty_queue(const StaticQueue* Q, const char* function_name) {
    if (StaticQueue_is_empty(Q)) {
        fprintf(stderr, "ERROR in '%s'\n", function_name);
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }
}

void check_full_queue(const StaticQueue* Q, const char* function_name) {
    if (StaticQueue_is_full(Q)) {
        fprintf(stderr, "ERROR in '%s'\n", function_name);
        fprintf(stderr, "Queue is full\n");
        exit(EXIT_FAILURE);
    }
}

void StaticQueue_enqueue(StaticQueue* Q, int val) {
    check_full_queue(Q, "StaticQueue_enqueue");

    Q->data[Q->end] = val;
    Q->end = (Q->end + 1) % Q->capacity;
    Q->size++;
}

int StaticQueue_peek(const StaticQueue* Q) {
    check_empty_queue(Q, "StaticQueue_peek");

    return Q->data[Q->begin];
}

int StaticQueue_dequeue(StaticQueue* Q) {
    check_empty_queue(Q, "StaticQueue_dequeue");

    int val = Q->data[Q->begin];
    Q->begin = (Q->begin + 1) % Q->capacity;
    Q->size--;

    return val;
}

void StaticQueue_print(const StaticQueue* Q) {
    printf("capacity: %ld\n", Q->capacity);
    printf("size: %ld\n", Q->size);
    printf("begin: %ld\n", Q->begin);
    printf("end: %ld\n\n", Q->end);

    long s, i;

    for (s = 0, i = Q->begin;
        s < Q->size;
        s++, i = (i + 1) % Q->capacity) {
        printf("%d, ", Q->data[i]);
    }
    puts("");
}