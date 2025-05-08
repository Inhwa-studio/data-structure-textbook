#pragma once

#include "./priority_queue.h"


Queue create_queue();

Queue generate_task();

void display_all(Queue task_queue);

void display_current(Queue task_queue);

Queue complete_task(Queue task_queue);

Queue add_task(Queue task_queue);
