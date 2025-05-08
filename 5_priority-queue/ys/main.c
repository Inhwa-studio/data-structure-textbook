#include <Windows.h>
#include <stdio.h>
#include <stdbool.h>
#include "./include/priority_queue.h"
#include "./include/simulate.h"

int main() {

    SetConsoleOutputCP(CP_UTF8);

    Queue task_queue;
    task_queue.nTask = 0;

    while (true) {

        printf("[ MENU ] 1: generate, 2: display, 3: current, 4: complete, 5: add, 6: quit\n");
        printf("Please enter a command:");
        
        int command;
        
        if (scanf("%d", &command) != 1) {
            printf("wrong input!!!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (command) {
            case 1:
                task_queue = generate_task();
                break;
            case 2:
                display_all(task_queue);
                break;
            case 3:
                display_current(task_queue);
                break;
            case 4:
                task_queue = complete_task(task_queue);
                break;
            case 5:
                task_queue = add_task(task_queue);
                break;
            case 6:
                printf("👋 Program terminated.\n");
                return 0;
            default:
                printf("wrong input!!!\n");
                break;
        }
    } 
}