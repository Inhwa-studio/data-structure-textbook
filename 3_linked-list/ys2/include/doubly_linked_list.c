#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubly_linked_list.h"

Node* create_list(){
    Node* head = malloc(sizeof(Node));
    if (head == NULL){
        printf("Error: malloc failed\n");
        return NULL;
    }

    head->next = head;
    head->prev = head;
    head->length = 0;
    head->now = 0;
    return head;
}

void insert(Node* head, int pos, char* data){
    Node* prevNode = head;

    for (int i = 0; i < pos; i++){
        prevNode = prevNode->next;
    }

    Node* curr = malloc(sizeof(Node));
    curr->nodeData = malloc(strlen(data) + 1);
    strcpy(curr->nodeData, data);
    curr->next = prevNode->next;
    curr->prev = prevNode;

    (prevNode->next)->prev = curr;
    prevNode->next = curr;

    if (pos == 0) {
        curr->length = 0;
        if (head->length >= 1) (curr->next)->length = -1;
    }
    else curr->length = -1;

    head->length++;
}

void rotate_right(Node** head){
    if (get_length(*head) >= 2){
        Node* target = (*head)->next;
        target->length = (*head)->length;
        (*head)->length = -1;
        (*head) = target;
        ((*head)->prev)->nodeData = (*head)->nodeData;
    }
}

void rotate_left(Node** head){
    if (get_length(*head) >= 2){
        Node* target = (*head)->prev;
        target->length = (*head)->length;
        (*head)->length = -1;
        (*head) = target;
        ((*head)->next)->nodeData = (*head)->nodeData;
    }
}

void del(Node* head, int pos){
    Node* prevNode = head;
    
    for (int i = 0; i < pos; i++){
        prevNode = prevNode->next;
    }

    Node* targetNode = prevNode->next;
    prevNode->next = targetNode->next;
    (targetNode->next)->prev = prevNode;

    free(targetNode->nodeData);
    free(targetNode);

    head->length--;
}

void clear(Node* head){
    Node* targetNode = head;
    for (int i = 0; i < head->length + 1; i++){
        targetNode = targetNode->next;
        free((targetNode->prev)->nodeData);
        free(targetNode->prev);
    }
}

char* get_entry(Node* head, int pos){
    Node* targetNode = head->next;
    for (int i = 0; i < pos; i++){
        targetNode = targetNode->next;
    }
    return targetNode->nodeData;
}

int get_length(Node* head){
    return head->length;
}

bool is_empty(Node* head){
    return head->length == 0;
}
