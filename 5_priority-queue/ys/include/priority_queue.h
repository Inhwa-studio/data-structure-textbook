#pragma once

#define MAN_LEN 30
#define MAX_TASKS 100

typedef struct {
    int priority;
    char name[MAN_LEN];
} element;

typedef struct {
    element tasks[MAX_TASKS + 1];
    int nTask;
} Queue;

Queue insert(Queue queue, element item);

Queue remove_task(Queue queue);

element peek(Queue queue);

void print_element(element node);

void print_queue(Queue queue);
