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
    if ((backIndex + 1) % capacity == frontIndex) { // circular queue
        int newCapacity = capacity * 2;
        T* newArr = new T[newCapacity];

        int jj = 0;
        for (int ii = frontIndex; ii != backIndex; ii = (ii + 1) % capacity) {
            newArr[jj++] = arr[ii];
        }
        newArr[jj++] = arr[backIndex];  // Copy the last element

        delete[] arr;  // Free old memory
        arr = newArr;
        
        frontIndex = 0;
        backIndex = jj - 1;
        capacity = newCapacity;
    }

    backIndex = (backIndex + 1) % capacity;
    arr[backIndex] = value;  // Insert new value at the back
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
