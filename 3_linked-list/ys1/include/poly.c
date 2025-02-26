#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node* create_poly(){
    Node* poly = create_list();

    int maxExpo = rand() % (10 - 5 + 1) + 5;

    int coef = rand() % 10 + 1;
    coef *= (rand() % 2) * 2 - 1;

    elem currTerm = {coef, maxExpo};
    insert_last(poly, currTerm);

    // 최고항 밑으로는 50%확률로 항을 추가했음
    for (int i = maxExpo - 1; i >= 0; i--){
        if (rand() % 2 == 1){
            int coef = rand() % 10 + 1;
            coef *= (rand() % 2) * 2 - 1;
            elem currTerm = {coef, i};
            insert_last(poly, currTerm);
        } 
    }
    return poly;
}

Node* add_poly(Node* poly1, Node* poly2){
    Node* poly3 = (Node*)malloc(sizeof(Node));
    poly3->next = NULL;

    Node* node1 = poly1->next;
    Node* node2 = poly2->next;

    while (node1 != NULL && node2 != NULL){
        if (node1->term.expo > node2->term.expo){
            insert_last(poly3, node1->term);
            node1 = node1->next;
        }
        else if (node1->term.expo < node2->term.expo){
            insert_last(poly3, node2->term);
            node2 = node2->next;
        }
        else {
            int expo = node1->term.expo;
            int coef = node1->term.coef + node2->term.coef;

            if (coef != 0){
                elem data = {coef, expo};
                insert_last(poly3, data);
            }
            node1 = node1->next;
            node2 = node2->next;
        }
    }
    
    if (node1 != NULL){
        while (node1 != NULL){
            insert_last(poly3, node1->term);
            node1 = node1->next;
        }
    }

    if (node2 != NULL){
        while (node2 != NULL){
            insert_last(poly3, node2->term);
            node2 = node2->next;
        }
    }

    return poly3;
}

void print_poly(Node* poly){
    Node* node = poly;
    if (node->next != NULL){
        node = node->next;
        printf("%dx^%d ", node->term.coef, node->term.expo);
    }
    while (node->next != NULL){
        node = node->next;
        if (node->term.expo > 1){
            if (node->term.coef > 0){
                printf("+ %dx^%d ", node->term.coef, node->term.expo);
            }
            else {
                printf("- %dx^%d ", - (node->term.coef), node->term.expo);
            }
        }
        else if (node->term.expo == 1){
            if (node->term.coef > 0){
                printf("+ %dx ", node->term.coef);
            }
            else {
                printf("- %dx ", - (node->term.coef));
            }
        }
        else {
            if (node->term.coef > 0){
                printf("+ %d", node->term.coef);
            }
            else {
                printf("- %d", - (node->term.coef));
            }
        }
    }
    printf("\n");
}
