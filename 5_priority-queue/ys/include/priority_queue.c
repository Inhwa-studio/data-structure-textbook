#include <stdio.h>
#include <stdbool.h>
#include "./priority_queue.h"

Queue insert(Queue queue, element item) {
    if (queue.nTask == MAX_TASKS) {
        printf("The task queue is full!!\n");
    }
    else {
        queue.nTask += 1;
        int curr = queue.nTask;
        queue.tasks[curr] = item;
        while (curr / 2 >= 1) {
            element parent = queue.tasks[curr / 2];
            element child = queue.tasks[curr];
            if (parent.priority < child.priority) {
                queue.tasks[curr / 2] = child;
                queue.tasks[curr] = parent;
                curr /= 2;
            }
            else break;
        }
    }
    return queue;
}

Queue remove_task(Queue queue) {
    queue.tasks[1] = queue.tasks[queue.nTask];
    queue.nTask -= 1;
    int curr = 1;

    while (curr * 2 <= queue.nTask) {
        element parent = queue.tasks[curr];
        int left = curr * 2;
        int right = curr * 2 + 1;
        int target = left;
        if (right <= queue.nTask && queue.tasks[right].priority > queue.tasks[left].priority) {
            target = right;
        }
        
        element child = queue.tasks[target];
        if (parent.priority < child.priority) {
            queue.tasks[target] = parent;
            queue.tasks[curr] = child;
            curr = curr * 2;
        }
        else break;
    }

    return queue;
}

element peek(Queue queue) {
    return queue.tasks[1];
}

void print_element(element node) {
    printf("%s (Priority: %d)\n", node.name, node.priority);
}

void print_queue(Queue queue) {
    for (int i = 1; i <= queue.nTask; i++) {
        printf("%d. ", i);
        print_element(queue.tasks[i]);
    }
}
