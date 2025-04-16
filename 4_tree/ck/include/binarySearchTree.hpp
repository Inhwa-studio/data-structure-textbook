#pragma once
#include <iostream>

using namespace std;

template <typename T>
class BST {
    
protected: 
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };
    typename BST<T>::Node* getRoot() const;

private:
    Node* root;

    // Private helper functions
    bool deleteNode(typename BST<T>::Node* node, T value); //
    typename BST<T>::Node* findMin(typename BST<T>::Node* node); //
    bool search(typename BST<T>::Node* node, T value) const; //
    void inorder(typename BST<T>::Node* node) const;
    void preorder(typename BST<T>::Node* node) const;
    void postorder(typename BST<T>::Node* node) const;
    int getHeight(typename BST<T>::Node* node) const;
    bool isEmpty(typename BST<T>::Node* node) const;
    void clear(typename BST<T>::Node*& node);

    
public:
    // Constructor & Destructor
    BST();
    ~BST();

    // Public methods
    bool insert(T value); //
    bool deleteValue(T value); // 
    bool search(T value) const; //
    T findMin() const; // 
    T findMax() const; // 
    void inorder() const;
    void preorder() const;
    void postorder() const;
    int getHeight() const;
    bool isEmpty() const;
    void clear();
    void print_tree();
};

// Include the implementation file
#include "binarySearchTree.inl"
