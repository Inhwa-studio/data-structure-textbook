#include "mp3.h"
#define MAX_LEN 20

Node* create_mp3(){
    Node* mp3 = create_list();
    return mp3;
}

void update_state(Node* mp3, int order){
    if (order == 1) {
        if (mp3->now > 1) mp3->now--;
    }
    else if (order == 2) {
        if (mp3->now < get_length(mp3)) mp3->now++;
    }
}

void insert_song(Node* mp3){
    printf("Song Name : ");
    char song[MAX_LEN + 1];
    scanf("%s", song);
    insert(mp3, mp3->now++, song);
}

void remove_song(Node* mp3){
    if (!is_empty(mp3)){
        del(mp3, mp3->now - 1);
        if (is_empty(mp3)) mp3->now = 0;
        else if (mp3->now > 1) mp3->now--;
    }
}

void print_curr_state(Node* mp3){
    if (is_empty(mp3)) {
        printf("mp3 is empty.\n");
    }
    else {
        Node* target = mp3->next;
        for (int i = 0; i < mp3->length; i++){
            if (mp3->now == i + 1){
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
