#include <iostream>
#include <cstdlib> 
#include <cstring> 
#include <ctime> 

#include "./include/priorityQueue.hpp"

int main() {
    PriorityQueue<string> pq;

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
                // task_queue = generate_task();
                break;
            case 2:
                // display_all(task_queue);
                break;
            case 3:
                // display_current(task_queue);
                break;
            case 4:
                // task_queue = complete_task(task_queue);
                break;
            case 5:
                // task_queue = add_task(task_queue);
                break;
            case 6:
                // printf("👋 Program terminated.\n");
                return 0;
            default:
                // printf("wrong input!!!\n");
                break;
        }
    } 



    // // 삽입
    // pq.insert("apple", 5);
    // pq.insert("banana", 3);
    // pq.insert("cherry", 1);
    // pq.insert("date", 4);

    // cout << "== Priority Queue ==" << endl;
    // pq.print_queue();

    // // peek
    // cout << "Top element (peek): " << pq.peek() << endl;

    // // remove
    // cout << "Removing top element: " << pq.remove() << endl;

    // // 다시 출력
    // cout << "After remove:" << endl;
    // pq.print_queue();
    // pq.print_queue();

    // // empty check
    // cout << "Is empty? " << boolalpha << pq.isEmpty() << endl;

    // // clear
    // pq.clear();
    // cout << "Queue cleared." << endl;
    // cout << "Is empty now? " << boolalpha << pq.isEmpty() << endl;

    return 0;
}
