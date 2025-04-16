#include "contactsBST.hpp"

// Constructor
ContactsBST::ContactsBST() : BST<Contact>() {}

// Search function to find a contact by name
Contact ContactsBST::search(const std::string& name) const {
    typename BST<Contact>::Node* current = this->getRoot();
    while (current) {
        if (current->data.getName() == name) {
            return current->data; // Contact found
        } else if (name < current->data.getName()) {
            current = current->left; // Move left
        } else {
            current = current->right; // Move right
        }
    }
    
    return Contact();  // 👈 returns "John Doe"
}
