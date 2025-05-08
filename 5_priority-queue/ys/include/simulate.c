#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "./priority_queue.h"
#include "./simulate.h"

Queue create_queue() {
    Queue task_queue;
    task_queue.nTask = 0;
    return task_queue;
}

Queue generate_task() {
    
    Queue task_queue = create_queue();
    
    int genTask;
    while (true) {
        printf("Enter number of tasks to generate: ");
        scanf("%d", &genTask);
        // 정수가 아닌 경우의 예외처리 필요
        if (genTask <= MAX_TASKS) break;
        else printf("There are currently %d remaining task positions.\n", MAX_TASKS);
    }

    srand(time(NULL));
    for (int i = 0; i < genTask; i++) {
        element data;
        data.priority = rand() % 10 + 1;
        sprintf(data.name, "Task%d", i);
        task_queue = insert(task_queue, data);
        printf("✅ %s (Priority: %d) added.\n", data.name, data.priority);
    }

    return task_queue;
}

void display_all(Queue task_queue) {
    if (task_queue.nTask == 0) {
        printf("⚠️  The queue is empty.\n");
    }
    else {
        printf("📋 Current Task Queue: \n");
        print_queue(task_queue);
    }
}

void display_current(Queue task_queue) {
    if (task_queue.nTask == 0) {
        printf("⚠️  The queue is empty.\n");
    }
    else {
        printf("🔥 Current Task: ");
        element current = peek(task_queue);
        print_element(current);
    }
}

Queue complete_task(Queue task_queue) {
    if (task_queue.nTask == 0) {
        printf("⚠️  The queue is empty.\n");
        return task_queue;
    }
    else {
        Queue after_queue;
        after_queue = remove_task(task_queue);
        printf("✅ %s completed.\n", peek(task_queue).name);
        return after_queue;
    }
}

Queue add_task(Queue task_queue) {
    element data;
    printf("Enter task name:");
    scanf("%s", data.name);
    printf("Enter priority (1~10):");
    scanf("%d", &data.priority); // 마찬가지로 예외처리 필요
    
    task_queue = insert(task_queue, data);
    printf("✅ %s (Priority: %d) added.\n", data.name, data.priority);
    return task_queue;
}
