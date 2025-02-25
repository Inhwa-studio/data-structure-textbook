#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node* create_list(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

void insert(Node* head, int pos, elem data){
    Node* prevNode = head;
    while (pos-- > 0){
        prevNode = prevNode->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->term = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void insert_last(Node* head, elem data){
    Node* prevNode = head;
    while (prevNode->next != NULL){
        prevNode = prevNode->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->term = data;
    newNode->next = NULL;
    prevNode->next = newNode;
}

void insert_first(Node* head, elem data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->term = data;
    newNode->next = head->next;
    head->next = newNode;
}

void del(Node* head, int pos){
    Node* prevNode = head;
    while (pos-- > 0){
        prevNode = prevNode->next;
    }
    Node* targetNode = prevNode->next;
    prevNode->next = targetNode->next;
    free(targetNode);
}

void clear(Node* head){
    Node* node = head->next;
    Node* nextNode;
    while (node != NULL){
        nextNode = node->next;
        free(node);
        node = nextNode;
    }
    free(head);
}

elem get_entry(Node* head, int pos){
    Node* node = head->next;
    while (pos-- > -1){
        node = node->next;
    }
    return node->term;
}

int get_length(Node* head){
    int length = 0;
    Node* node = head;
    while (node->next != NULL){
        node = node->next;
        length++;
    }
    return length;
}

bool is_empty(Node* head){
    return head->next == NULL;
}

void print_list(Node* head){
    Node* node = head;
    while (node->next != NULL){
        node = node->next;
        printf("%dx^%d -> ", node->term.coef, node->term.expo);
    }
    printf("NULL\n");
}
