#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int* stack;
    int top;
} Stack;

Stack* create(int size){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->size = size;
    s->stack = (int*)malloc(size * sizeof(int));
    s->top = 0;
    printf("\n########## Stack with size %d has been created. ##########\n", size);
    return s;
}

int is_full(Stack* s){
    return s->top == s->size;
}

int is_empty(Stack* s){
    return s->top == 0;
}

void push(Stack* s, int item){
    if (is_full(s) == 1) {
        printf("\n########## the stack is full!!! ##########\n");
    }
    else {
        s->top += 1;
        s->stack[s->top] = item;
        printf("\n########## %d is pushed. ##########\n", item);
    }
}

int pop(Stack* s){
    if (is_empty(s) == 1) {
        printf("\n########## the stack is empty!!! ##########\n");
    }
    else {
        printf("\n########## %d is popped. ##########\n", s->stack[s->top]);
        return s->top--;
    }
}

int peek(Stack* s){
    if (is_empty(s) == 1) {
        printf("\n########## the stack is empty!!! #########\n");
    }
    else {
        printf("\n########## %d is peeked. ##########\n", s->stack[s->top]);
        return s->top;
    }
}

int main(){
    int size;
    printf("Please enter the desired stack size : ");
    scanf("%d", &size);
    Stack* myStack = create(size);

    while (1){
        int order;
        printf("----------------------------------\n");
        printf("Enter the action number to perform\n");
        printf("\n");
        printf("1 Verify that the stack is full\n");
        printf("2 Verify that the stack is empty\n");
        printf("3 Insert an element into the stack\n");
        printf("4 Delete an element in a stack\n");
        printf("5 Check the elements in the stack\n");
        printf("0 Exit\n");
        printf("Your input : ");
        scanf("%d", &order);

        if (order == 0) {
            free(myStack->stack);
            free(myStack);
            break;
        }
        else{
            switch (order){
            case 1:
                if (is_full(myStack)){
                    printf("\n########## the stack is full. ##########\n");
                }
                else{
                    printf("\n########## the stack is NOT full. ##########\n");
                }
                break;
            case 2:
                if (is_empty(myStack) == 1) {
                    printf("\n########## the stack is empty. ##########\n");
                }
                else {
                    printf("\n########## the stack is NOT empty. ##########\n");
                }
                break;
            case 3:
                if (is_full(myStack)){
                    printf("\n########## the stack is full. ##########\n");
                }
                else{
                    int item;
                    printf("\nEnter a number to insert in the stack : ");
                    scanf("%d", &item);
                    push(myStack, item);
                    }
                break;
            case 4:
                pop(myStack);
                break;
            case 5:
                peek(myStack);
                break;
            default:
                printf("\nwrong input!!\n");
                break;
            }
        }
    }
    return 0;
}