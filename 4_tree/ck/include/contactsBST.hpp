#pragma once
#include "binarySearchTree.hpp"
#include "Contact.hpp"

class ContactsBST : public BST<Contact> {
public:
    ContactsBST();

    // Search function to find a contact by name
    Contact search(const std::string& name) const;
};
