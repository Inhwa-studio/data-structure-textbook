#include <stdio.h>
#include <stdbool.h>
#include "./include/doubly_linked_list.h"
#include "./include/mp3.h"

int main(){
    Node* mp3 = create_mp3();

    while (true) {
        printf(" Please enter a command [1: left, 2: right, 3: insert, 4: remove, 5: quit] : ");
        int order;
        scanf("%d", &order);

        if (order == 5) {
            clear(mp3);
            break;
        }
        else {
            switch (order) {
            case 1:
                update_state(mp3, order);
                print_curr_state(mp3);
                break;
            case 2:
                update_state(mp3, order);
                print_curr_state(mp3);
                break;
            case 3:
                insert_song(mp3);
                print_curr_state(mp3);
                break;
            case 4:
                remove_song(mp3);
                print_curr_state(mp3);
                break;
            default:
                printf("wrong input!!\n");
                break;
            }
        }
    }
}