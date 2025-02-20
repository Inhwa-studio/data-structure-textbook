#include <optional>
#include <stdexcept>  // Required for std::out_of_range

// Constructor
template <typename T>
Queue<T>::Queue(int size) {
    capacity = size * 2;  
    arr = new T[capacity];  // Allocate memory for queue
    frontIndex = 0;
    backIndex = -1;
}

template <typename T>
bool Queue<T>::is_empty() {
    return backIndex < frontIndex;
}

// Inserts an element into the queue (enqueue)
template <typename T>
void Queue<T>::enqueue(T value) {
    if (backIndex - frontIndex + 1 == capacity) {  // If queue is full, expand capacity
        int newCapacity = capacity * 2;
        T* newArr = new T[newCapacity];

        // Copy existing elements in queue order
        for (int ii = frontIndex; ii <= backIndex; ++ii) {
            newArr[ii - frontIndex] = arr[ii];
        }

        delete[] arr;  // Free old memory
        arr = newArr;
        backIndex -= frontIndex;
        frontIndex = 0;
        capacity = newCapacity;
    }

    arr[++backIndex] = value;  // Insert new value at the back
}

// Removes an element from the queue (dequeue)
template <typename T>
T Queue<T>::dequeue() {
    if (is_empty()) {
        // return std::nullopt;  // Return empty state
        static T dummy;
        return dummy;
    }
    T value = arr[frontIndex];
    frontIndex++;
    return value;
}

// Returns the front element of the queue
template <typename T>
T& Queue<T>::peek() {
    if (is_empty()) {
        // throw std::out_of_range("Queue is empty! Cannot peek.");
        // return T();
        static T dummy;
        return dummy;
    }
    return arr[frontIndex];  // Return front element
}

// Destructor: Releases allocated memory
template <typename T>
Queue<T>::~Queue() {
    delete[] arr;
}
