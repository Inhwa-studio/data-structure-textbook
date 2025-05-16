#include "taskManager.hpp"

void TaskManager::generate_task(PriorityQueue<std::string>& queue) {
    int genTask;
    while (true) {
        std::cout << "Enter number of tasks to generate: ";
        std::cin >> genTask;

        // Input validation
        if (std::cin.fail()) {
            std::cin.clear(); // clear error flag
            std::cin.ignore(10000, '\n'); // discard bad input
            std::cout << "❌ Invalid input. Please enter an integer.\n";
            continue;
        }

        if (genTask <= MAX_TASKS) {
            break;
        }
        else {
            std::cout << "❗ Only " << MAX_TASKS << " task positions are available.\n";
        }
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int ii = 0; ii < genTask; ++ii) {

        int priority = std::rand() % 100 + 1;
        std::string task_name = "Task" + std::to_string(ii);

        queue.insert(task_name, priority);

        std::cout << "✅ " << task_name << " (Priority: " << priority << ") added.\n";
    }
}

void TaskManager::display_all(PriorityQueue<std::string> queue){
    queue.print_queue();        
}

void TaskManager::display_current(PriorityQueue<std::string> queue){
    queue.print_TopPriority();
}

void TaskManager::complete_task(PriorityQueue<std::string>& queue){
    std::string task_name = queue.peek();
    std::cout << "✅ " << task_name << " completed\n";
    queue.remove();
}


void TaskManager::add_task(PriorityQueue<std::string>& queue) {
    std::string name;
    int priority;

    std::cout << "Enter task name: ";
    std::cin.ignore(); // flush leftover newline from previous input
    std::getline(std::cin, name);

    while (true) {
        std::cout << "Enter priority (1~100): ";
        std::cin >> priority;

        if (std::cin.fail() || priority < 1 || priority > 100) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "❌ Invalid input. Please enter a number between 1 and 100.\n";
        } else {
            break;
        }
    }

    queue.insert(name, priority);

    std::cout << "✅ " << name << " (Priority: " << priority << ") added.\n";
}