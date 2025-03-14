#pragma once
#include <iostream>

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(T value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    int length;

public:
    DoublyLinkedList(); 
    ~DoublyLinkedList();

    void insert(int pos, T item);
    void insert_last(T item);
    void insert_front(T item);
    void delete_at(int pos); // delete is a reserved keyword in C++, used for deallocating dynamic memory
    void clear();
    T get_entry(int pos);
    const int get_length();
    bool is_empty();
};

#include "doublyLinkedList.inl"
