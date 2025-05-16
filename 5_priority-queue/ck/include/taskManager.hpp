#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "priorityQueue.hpp"

#define MAX_TASKS 100

class TaskManager {
public:
    // Generate random tasks and add to the queue
    static void generate_task(PriorityQueue<std::string>& queue);

    // Print all tasks in priority order
    static void display_all(PriorityQueue<std::string> queue);

    // Show the task with the highest priority
    static void display_current(PriorityQueue<std::string> queue);

    // Remove the task with the highest priority
    static void complete_task(PriorityQueue<std::string>& queue);

    // Let the user add a new task manually
    static void add_task(PriorityQueue<std::string>& queue);
};