#include <stdio.h>
#include "address.h"

TreeNode* create_address() {
    TreeNode* address = create_tree();
    return address;
}

TreeNode* add_address(TreeNode* address) {
    element data;
    printf("Name : ");
    scanf(" %[^\n]", data.name);
    printf("Phone Number : ");
    scanf(" %[^\n]", data.phone);
    printf("Email : ");
    scanf(" %[^\n]", data.email);

    printf("Contact '%s' added successfully.\n\n", data.name);
    return insert(address, data);
}

void search_address(TreeNode* address) {
    char keyName[NAME_LEN + 1];
    printf("Search Name : ");
    scanf(" %[^\n]", keyName);

    TreeNode* target;
    target = search(address, keyName);
    
    printf("Search Result : \n");
    
    if (target == NULL) printf("There is no one named %s.\n\n", keyName);
    else {
        display_node(target);
        printf("\n");
    }
}

TreeNode* delete_address(TreeNode* address) {
    char keyName[NAME_LEN + 1];
    printf("Delete Name : ");
    scanf(" %[^\n]", keyName);

    TreeNode* target;
    target = search(address, keyName);
    if (search(address, keyName) == NULL) {
        printf("There is no one named %s.\n\n", keyName);
        return address;
    }
    else {
        printf("Contact '%s' deleted successfully.\n\n", keyName);
        return delete_node(address, target->key);
    }
}

void display_node(TreeNode* target) {
    printf("Name : %s, Phone Number : %s, Email : %s\n", target->key.name, target->key.phone, target->key.email);
}

void display_address(TreeNode* address) {
    if (is_empty(address)) printf("There is no contact!!!\n");
    else {
        int counter = 1;
        printf("Displaying all contacts:\n");
        print_tree(address, &counter);
    }
    printf("\n");
}
