#include <stdio.h>
#include <stdbool.h>
#include "./include/binary_search_tree.h"
#include "./include/address.h"

int main() {

    TreeNode* address = NULL;

    while (true) {

        printf("Please enter a command [1: add, 2: search, 3: delete, 4: display all, 5: quit]:");
        
        int command;
        
        if (scanf("%d", &command) != 1) {
            printf("wrong input!!!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (command) {
            case 1:
                address = add_address(address);
                break;
            case 2:
                search_address(address);
                break;
            case 3:
                address = delete_address(address);
                break;
            case 4:
                display_address(address);
                break;
            case 5:
                clear(address);
                return 0;
            default:
                printf("wrong input!!!\n");
                break;
        }
    } 
}