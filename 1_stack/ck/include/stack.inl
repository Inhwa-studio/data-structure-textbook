#include "stack.hpp"

// Constructor: Initializes the stack with dynamic memory allocation
template <typename T>
Stack<T>::Stack(int size) {
    capacity = size * 2;  
    arr = new T[capacity];  // Allocate memory for stack
    topIndex = -1;
}

template <typename T>
bool Stack<T>::is_empty() {
    return topIndex == -1;
}

template <typename T>
void Stack<T>::push(T value) {
    if (topIndex == capacity - 1) {  // If stack is full, expand capacity
        int newCapacity = capacity * 2;
        T* newArr = new T[newCapacity];

        // Copy existing elements to new array
        for (int ii = 0; ii < capacity; ++ii) {
            newArr[ii] = arr[ii];
        }

        delete[] arr;  // Free old memory
        arr = newArr;
        capacity = newCapacity;
    }

    arr[++topIndex] = value;  // Insert new value
}

template <typename T>
void Stack<T>::pop() {
    if (topIndex == -1) {
        return; 
    }
    topIndex--;
}

template <typename T>
T Stack<T>::peek() {
    return (topIndex == -1) ? T() : arr[topIndex];  // Return default value if empty
}


// Destructor
template <typename T>
Stack<T>::~Stack() {
    delete[] arr;
}
