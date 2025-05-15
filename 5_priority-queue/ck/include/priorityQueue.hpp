#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
class PriorityQueue {

protected:
    struct Node {
        T data;
        int priority;
        Node(T d, int p) : data(d), priority(p) {}
        bool operator<(const Node& other) const {
            return priority > other.priority; // lower value = higher priority
        }
    };

private:
    vector<Node> heap;

    // private helpers
    void heapifyUp(int index);
    static void heapifyDownAt(std::vector<Node>& h, int index, int size);

public:
    PriorityQueue();
    ~PriorityQueue();

    void insert(T value, int priority);
    T remove();         // delete()
    T peek() const;
    bool isEmpty() const;
    bool isFull() const;
    void clear();
    void print_queue() const;
};
#include "priorityQueue.inl"

