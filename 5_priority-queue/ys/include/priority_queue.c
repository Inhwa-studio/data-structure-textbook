#include <stdio.h>
#include <stdbool.h>
#include "./priority_queue.h"


Queue heapifyup(Queue queue, int index) {
    int parent_idx = index / 2;
    while (parent_idx >= 1) {
        Node parent = queue.tasks[parent_idx];
        Node child = queue.tasks[index];
        if (parent.priority < child.priority) {
            queue.tasks[parent_idx] = child;
            queue.tasks[index] = parent;
            index /= 2;
            parent_idx /= 2;
        }
        else break;
    }
    return queue;
}

Queue heapifydown(Queue queue, int index) {
    while (index * 2 <= queue.nTask) {
        Node parent = queue.tasks[index];
        int left = index * 2;
        int right = index * 2 + 1;
        int target = left;

        if (right <= queue.nTask && queue.tasks[right].priority > queue.tasks[left].priority) {
            target = right;
        }

        Node child = queue.tasks[target];
        if (parent.priority < child.priority) {
            queue.tasks[target] = parent;
            queue.tasks[index] = child;
            index = index * 2;
        }
        else break;
    }

    return queue;
}

Queue insert(Queue queue, Node item) {
    if (queue.nTask == MAX_TASKS) {
        printf("The task queue is full!!\n");
    }
    else {
        queue.nTask += 1;
        int curr = queue.nTask;
        queue.tasks[curr] = item;

        queue = heapifyup(queue, curr);
    }
    return queue;
}

Queue remove_task(Queue queue) {
    queue.tasks[1] = queue.tasks[queue.nTask];
    queue.nTask -= 1;
    int curr = 1;

    queue = heapifydown(queue, curr);

    return queue;
}

Node peek(Queue queue) {
    return queue.tasks[1];
}

void print_node(Node node) {
    printf("%s (Priority: %d)\n", node.name, node.priority);
}

void print_queue(Queue queue) {
    while (!is_empty(queue)) {
        print_node(peek(queue));
        queue = remove_task(queue);
    }
}

int is_empty(Queue queue) {
    return queue.nTask == 0;
}
