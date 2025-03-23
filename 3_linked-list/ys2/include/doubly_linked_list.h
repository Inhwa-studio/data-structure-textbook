#pragma once

#include <stdbool.h>
#include <stdbool.h>
#define MAX_LEN 20

typedef struct Node {
    char* nodeData;
    struct Node* next;
    struct Node* prev;
    int idx;
} Node;

Node* create_list();

void insert(Node* head, int pos, char* data);
void rotate_right(Node** head);
void rotate_left(Node** head);
void del(Node* head, int pos);
void clear(Node* head);
char* get_entry(Node*head, int pos);
int get_length(Node* head);
bool is_empty(Node* head);
void print_list(Node* head);