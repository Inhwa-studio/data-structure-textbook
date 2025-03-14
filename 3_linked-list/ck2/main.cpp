#include <iostream>
#include <cstdlib> 
#include <cstring> 
#include <ctime> 

#include "./include/doublyLinkedList.hpp"

int main() {
    DoublyLinkedList<std::string> mp3;

    int command = 0;
    int idx     = 0;
    char songName[64];

    while( command != 5 ){
        printf("Please enter a command [1 : left, 2 : right, 3 : insert, 4 : remove, 5: quit] : ");

        // scanf("%d", &command);
        if (scanf("%d", &command) != 1) {   // 해결
            // If scanf fails to read an integer, clear input buffer and print error
            printf("Invalid input! Please enter a number between 1 and 5.\n");
            while (getchar() != '\n');  // Clear input buffer
            continue;  // Restart loop
        }

        if( command == 1){ // move left
            if (idx > 0) {
                --idx;
            }
            else{
                idx = mp3.get_length()-1;
            }
        }
        else if (command == 2) { // move right
            if (idx < mp3.get_length() - 1) {
                ++idx;
            }
            else{
                idx = 0;
            }
        }        
        else if (command == 3) { // Insert a new song at the current position
            printf("song name : ");
            scanf(" %[^\n]", songName); // Read full line (with spaces)

            if (mp3.is_empty() || idx == mp3.get_length()) {
                mp3.insert_last(std::string(songName)); // Insert at the end
                idx = mp3.get_length() - 1;
            } else {
                mp3.insert(idx + 1, std::string(songName)); // Insert at the next position
                ++idx;
            }
        }
        else if (command == 4) { // Remove the current song

            if (!mp3.is_empty()) {
                mp3.delete_at(idx);
                // Adjust the current index after deletion
                if (idx >= mp3.get_length()) {
                    idx = mp3.get_length() - 1;
                }
            }
        }
        else if (command == 5) {
            break;
        }
        // else{
            // printf("Please enter a number between 1 and 5.\n");   
        // }

        for ( int ii = 0; ii < mp3.get_length(); ++ii){
            printf("<-| ");
            char ch[64];
            strcpy(ch, mp3.get_entry(ii).c_str());
            if ( ii == idx){
                printf("#%s# |-> ", ch);
            }
            else{
                printf("%s |-> ", ch);
            }            
        }
        printf("\n\n");
    }
// 이거 지금 존나 이상함 번호 안누르고 그냥 노래 제목 쓰면 들어감

    return 0;
}
