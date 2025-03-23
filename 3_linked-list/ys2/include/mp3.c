#include "mp3.h"
#define MAX_LEN 20

Node* create_mp3(){
    Node* mp3 = create_list();
    return mp3;
}

void update_state(Node* mp3, int order){
    if (order == 1) {
        if (mp3->idx > 1) mp3->idx--;
    }
    else if (order == 2) {
        if (mp3->idx < get_length(mp3)) mp3->idx++;
    }
}

void insert_song(Node* mp3){
    printf("Song Name : ");
    char song[MAX_LEN + 1];
    scanf(" %[^\n]", song);
    insert(mp3, mp3->idx++, song);
}

void remove_song(Node* mp3){
    if (!is_empty(mp3)){
        if (mp3->idx == get_length(mp3)) {
            mp3->idx--;
            del(mp3, mp3->idx);
        }
        else del(mp3, mp3->idx - 1);
    }
}

void print_curr_state(Node* mp3){
    if (is_empty(mp3)) {
        printf("mp3 is empty.\n");
    }
    else {
        Node* target = mp3->next;
        for (int i = 0; i < get_length(mp3); i++){
            if (mp3->idx == i + 1){
                printf("<-|## %s ##|->", target->nodeData);
                target = target->next;    
            }
            else {
                printf("<-| %s |->", target->nodeData);
                target = target->next;
            }
        }
        printf("\n");
    }
}
