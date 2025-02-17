#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue* create(int size){
    queue* myQue = (queue*) malloc(sizeof(queue));
    myQue->list = (elem*) malloc(size * sizeof(elem));
    myQue->front = 0;
    myQue->rear = 0;
    myQue->size = size;

    // printf("\n########## Queue with size %d has been created. ##########\n", size);
    return myQue;
}

int is_full(queue* que){
    return que->front == (que->rear + 1) % que->size;
}

int is_empty(queue* que){
    return que->front == que->rear;
}

void enqueue(queue* que, elem item){
    if (is_full(que)) printf("\n########## queue is full!!!!!##########\n");
    else {
        que->rear = (que->rear + 1) % que->size;
        que->list[que->rear] = item;
        // printf("item %d has enqueued.\n", item);
    }
}

elem dequeue(queue* que){
    if (is_empty(que)) {
        // printf("\n########## queue is empty!!!!!##########\n");
    }
    else {
        que->front = (que->front + 1) % que->size;
        elem item = que->list[que->front];
        // printf("\n########## item %d has dequeued.##########\n", item);
        return item;
    }
}

elem peek(queue* que){
    if (is_empty(que)) {
        // printf("\n########## queue is empty!!!!!##########\n");
    }
    else {
        elem item = que->list[(que->front + 1) % que->size];
        // printf("\n########## item %d has peeked.##########\n", item);
        return item;
    }
}
