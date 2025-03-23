// #include <optional>
#include <stdexcept>  // Required for std::out_of_range

// Constructor
template <typename T>
Queue<T>::Queue(int size_) {
    capacity = size_+1;
    arr = new T[capacity];  // Allocate memory for queue
    frontIndex = 0;
    backIndex = 0;
    size = 0;
}

template <typename T>
bool Queue<T>::is_empty() {
    return size == 0;  // Correct condition
}

// Inserts an element into the queue (enqueue)
template <typename T>
void Queue<T>::enqueue(T value) {
    if (size == capacity - 1) { // circular queue
        return;
    }

    arr[backIndex] = value;  // Insert new value at the back        
    backIndex = (backIndex + 1) % capacity;
    ++size;
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
    frontIndex = (frontIndex + 1) % capacity;  // Wrap around circularly
    size--;
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
