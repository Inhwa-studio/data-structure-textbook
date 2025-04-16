#include <iostream>
#include <cstdlib> 
#include <cstring> 
#include <ctime> 

#include "./include/binarySearchTree.hpp"
#include "./include/contactsBST.hpp"
#include "./include/contact.hpp"

int main() {

    // BST<int> bst;
    // bst.insert(10);
    // bst.insert(20);
    // bst.insert(30);
    // bst.insert(40);
    
    // // bst.print_tree();



    ContactsBST contacts;

    std::string name, phoneNumber, email;
    while (1) {
        printf("Please enter a command [1: add, 2: search, 3: delete, 4: display all, 5: quit] : ");
        
        int command;
        if (!(std::cin >> command)) {
            std::cin.clear();  // Clear error flag
            std::cin.ignore(10000, '\n');  // Discard invalid input
            std::cout << "Invalid input! Please enter a number between 1 and 5.\n";
            continue;
        }
    
        // Validate range
        if (command < 1 || command > 5) {
            printf("Please enter a number between 1 and 5.\n");
            continue;
        }
        // // Process command
        if ( command == 1 ){
            std::cout << "Name: ";
            std::getline(std::cin >> std::ws, name);  // 버퍼 정리 후 입력 받기
        
            std::cout << "Phone Number: ";
            std::getline(std::cin, phoneNumber);
        
            std::cout << "Email: ";
            std::getline(std::cin, email);

            Contact contact(name, phoneNumber, email);
            if ( contacts.insert(contact) ){ // for now the contact is added only if the name is unique
                std::cout << "Contact '" << name << "' added successfully " << std::endl;
            }
            else{
                std::cout << "Contact '" << name << "' Could not add this information" << std::endl;
            };

            // std::cout << contact;
        }
        else if( command == 2 ){
            std::cin.ignore();
            std::cout << "Search Name: ";
            std::getline(std::cin >> std::ws, name);  // 버퍼 정리 후 입력 받기

            Contact searchContact = contacts.search(name);
            
            if ( searchContact == Contact() ){
                std::cout << "Could not find the contact by name" << std::endl;
            }
            else{
                std::cout << "Search Result: ";
                std::cout << searchContact << std::endl;
            }
        }
        else if( command == 3 ){
            std::cin.ignore();
            std::cout << "Delete Name: " << std::endl;
            std::getline(std::cin, name);
            std::cout << name << std::endl;

            if ( contacts.deleteValue(Contact(name)) ){
                std::cout << "Contact '" << name << "' deleted successfully." << std::endl;
            }
            else{
                std::cout << "Contact '" << name << "' does not exist in contacts  " << std::endl;
            }
        }
        else if( command == 4 ){
            contacts.preorder();
            // contacts.print_tree();
            
            
        }
        else if( command == 5 ){
            std::cout << "Closing the program" << std::endl;
            break;            
        }
    }
    
    return 0;
}