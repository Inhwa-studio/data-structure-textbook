#pragma once
#include <iostream>

template <typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* head;
    int length;

public:
    SinglyLinkedList(); 
    ~SinglyLinkedList();

    void insert(int pos, T item);
    void insert_last(T item);
    void insert_first(T item);
    void delete_at(int pos); // delete is a reserved keyword in C++, used for deallocating dynamic memory
    void clear();
    T get_entry(int pos);
    const int get_length();
    bool is_empty();
    void print_list();
};

#include "linkedList.inl"
