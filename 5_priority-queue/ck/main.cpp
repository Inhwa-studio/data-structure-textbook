#include <iostream>
#include <cstdlib> 
#include <cstring> 
#include <ctime> 

#include "./include/priorityQueue.hpp"
#include "./include/taskManager.hpp "

int main() {
    PriorityQueue<string> pq;

    while (true) {
        std::cout << "\n[ MENU ]\n";
        std::cout << "  1: Generate random tasks\n";
        std::cout << "  2: Display all tasks\n";
        std::cout << "  3: Display current task\n";
        std::cout << "  4: Complete current task\n";
        std::cout << "  5: Add new task\n";
        std::cout << "  6: Quit\n";
        std::cout << "Please enter a command: ";

        int command;
        std::cin >> command;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "❌ Invalid input. Please enter a number between 1 and 6.\n";
            continue;
        }
        
        switch (command) {
            case 1:
                TaskManager::generate_task(pq);
                break;
            case 2:
                TaskManager::display_all(pq);
                break;
            case 3:
                TaskManager::display_current(pq);
                break;
            case 4:
                TaskManager::complete_task(pq);
                break;
            case 5:
                TaskManager::add_task(pq);
                break;
            case 6:
                std::cout << "👋 Program terminated.\n";
                return 0;
            default:
                std::cout << "❌ Invalid menu option. Try again.\n";
                break;
        }
    } 
    return 0;
}
