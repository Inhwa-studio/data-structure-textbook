#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "./binary_search_tree.h"

TreeNode* create_tree() {
    TreeNode* root = malloc(sizeof(TreeNode));
    if (root == NULL){
        printf("Error: malloc failed\n");
        return NULL;
    }

    root->left = NULL;
    root->right = NULL;
    return root;
}

int compare(char name1[], char name2[]) {
    return strcmp(name1, name2);
}

TreeNode* new_node(element item) {
    TreeNode* node = malloc(sizeof(TreeNode));
    node->key = item;
    node->right = NULL;
    node->left = NULL;
    return node;
}

TreeNode* insert(TreeNode* tree, element item) {
    if (tree == NULL) return new_node(item);
    else {
        if (compare(item.name, tree->key.name) < 0) tree->left = insert(tree->left, item);
        else if (compare(item.name, tree->key.name) > 0) tree->right = insert(tree->right, item);
        return tree; // 겹치는 키는 없다고 가정했음을 기억!
    }
}

TreeNode* delete_node(TreeNode* tree, element item) {
    if (tree == NULL) return tree;
    else {
        if (compare(item.name, tree->key.name) < 0) tree->left = delete_node(tree->left, item);
        else if (compare(item.name, tree->key.name) > 0) tree->right = delete_node(tree->right, item);
        else {
            if (tree->left == NULL) {
                TreeNode* tmp = tree->right;
                free(tree);
                return tmp;
            }
            else if (tree->right == NULL) {
                TreeNode* tmp = tree->left;
                free(tree);
                return tmp;
            }
            else {
                TreeNode* tmp = tree->right;
                while (tmp->left != NULL) {
                    tmp = tmp->left;
                }
                tree->key = tmp->key;
                tree->right = delete_node(tree->right, tmp->key);
            }
        }
        return tree;
    }

}

TreeNode* search(TreeNode* tree, char name[]) {
    while (tree != NULL) {
        if (compare(name, tree->key.name) == 0) return tree;
        else if (compare(name, tree->key.name) < 0) tree = tree->left;
        else tree = tree->right;
    }
    return tree;
}

bool is_empty(TreeNode* tree) {
    return tree == NULL;
}

void clear(TreeNode* tree) {
    if (tree == NULL) return;
    clear(tree->left);
    clear(tree->right);
    free(tree);
}

void print_tree(TreeNode* tree) {
    if (tree != NULL) {
        print_tree(tree->left);
        printf("Name: %s, Phone Number: %s, Email: %s\n", tree->key.name, tree->key.phone, tree->key.email);
        print_tree(tree->right);
    }
}
