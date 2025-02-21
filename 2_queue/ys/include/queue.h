#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nCustomer;
    int arriveTime;
    int serviceTime;
    int playTime;
} elem;

typedef struct {
    elem* list;
    int front;
    int rear;
    int size;
} queue;

queue* create(int size);

int is_full(queue* que);

int is_empty(queue* que);

void enqueue(queue* que, elem item);

elem* dequeue(queue* que);

elem* peek(queue* que);
