#pragma once

#include <stdbool.h>
#define NAME_LEN 30
#define PHONE_LEN 15
#define EMAIL_LEN 30

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    char email[EMAIL_LEN];
} element;

typedef struct TreeNode {
    element key;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* create_tree();
int compare(char name1[], char name2[]);
TreeNode* new_node(element item);
TreeNode* insert(TreeNode* tree, element item);
TreeNode* delete_node(TreeNode* tree, element item);
TreeNode* search(TreeNode* tree, char name[]);
// TreeNode* find_min(TreeNode* tree);
// TreeNode* find_max(TreeNode* tree);
// void inorder(TreeNode* tree);
// void preorder(TreeNode* tree);
// void postorder(TreeNode* tree);
// int get_height(TreeNode* tree);
bool is_empty(TreeNode* tree);
void clear(TreeNode* tree);
void print_tree(TreeNode* tree);