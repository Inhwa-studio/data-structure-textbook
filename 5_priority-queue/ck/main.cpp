#include <iostream>
#include <cstdlib> 
#include <cstring> 
#include <ctime> 

#include "./include/priorityQueue.hpp"

int main() {
    PriorityQueue<string> pq;

    // 삽입
    pq.insert("apple", 5);
    pq.insert("banana", 3);
    pq.insert("cherry", 1);
    pq.insert("date", 4);

    cout << "== Priority Queue ==" << endl;
    pq.print_queue();

    // peek
    cout << "Top element (peek): " << pq.peek() << endl;

    // remove
    cout << "Removing top element: " << pq.remove() << endl;

    // 다시 출력
    cout << "After remove:" << endl;
    pq.print_queue();
    pq.print_queue();

    // empty check
    cout << "Is empty? " << boolalpha << pq.isEmpty() << endl;

    // clear
    pq.clear();
    cout << "Queue cleared." << endl;
    cout << "Is empty now? " << boolalpha << pq.isEmpty() << endl;

    return 0;
}
