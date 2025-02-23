#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int coef;
    int expo;
} elem;

typedef struct Node{
    elem port;
    struct Node* next;
} Node;

void insert(Node* head, int pos, elem data);
void insert_last(Node* head, elem data);
void insert_first(Node* head, elem data);

void delete(Node* head, int pos);
void clear(Node* head);

elem get_entry(Node*head, int pos);
int get_length(Node* head);

bool is_empty(Node* head);
// bool is_full(Node* head);

void print_list(Node* head);