

#pragma once
#include <iostream>

template <typename T>
class Queue {
private:
    T* arr;          
    int capacity;    // Queue capacity
    int frontIndex;    // Index of the front element
    int backIndex;    // Index of the back element
    int size;

public:
Queue(int size_);
    void enqueue(T value);
    T dequeue();
    T& peek();
    bool is_empty();
    ~Queue();
};

#include "queue.inl" // Template implementation should be included in the header

