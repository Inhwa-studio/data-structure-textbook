

#pragma once


#include <iostream>

template <typename T>
class Stack {
private:
    T* arr;          
    int capacity;    // Stack capacity
    int topIndex;    // Index of the top element

public:
    Stack(int size);
    void push(T value);
    void pop();
    T peek();
    bool is_empty();
    ~Stack();
};

#include "stack.inl" // Template implementation should be included in the header

