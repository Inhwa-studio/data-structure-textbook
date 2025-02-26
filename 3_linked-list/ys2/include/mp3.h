#pragma once

#include <stdio.h>

Node* create_mp3();
void update_state(Node* mp3, int order);
void insert_song(Node* mp3);
void remove_song(Node* mp3);
void print_curr_state(Node* mp3);