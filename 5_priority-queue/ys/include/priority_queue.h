#pragma once

#define MAN_LEN 30
#define MAX_TASKS 100

typedef struct {
    int priority;
    char name[MAN_LEN];
} Node;

typedef struct {
    Node tasks[MAX_TASKS + 1];
    int nTask;
} Queue;

Queue heapifyup(Queue queue, int index);

Queue heapifydown(Queue queue, int index);

Queue insert(Queue queue, Node item);

Queue remove_task(Queue queue);

Node peek(Queue queue);

void print_node(Node node);

void print_queue(Queue queue);

int is_empty(Queue queue);
