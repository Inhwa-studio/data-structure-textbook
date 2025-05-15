#pragma once

template <typename T>
PriorityQueue<T>::PriorityQueue() {}

template <typename T>
PriorityQueue<T>::~PriorityQueue() {
    clear();
}

template <typename T>
void PriorityQueue<T>::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

template <typename T>
void PriorityQueue<T>::heapifyDownAt(std::vector<Node>& h, int index, int size) {
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && h[left] < h[smallest]) {
            smallest = left;
        }
        if (right < size && h[right] < h[smallest]) {
            smallest = right;
        }

        if (smallest != index) {
            std::swap(h[index], h[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

template <typename T>
void PriorityQueue<T>::insert(T value, int priority) {
    heap.push_back(Node(value, priority));
    heapifyUp(heap.size() - 1);
}

template <typename T>
T PriorityQueue<T>::remove() {
    if (isEmpty()){
        throw runtime_error("Priority queue is empty!");
    }
    
    T top = heap[0].data;
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDownAt(heap, 0, heap.size());
    return top;
}

template <typename T>
T PriorityQueue<T>::peek() const {
    if (isEmpty()){
        throw runtime_error("Priority queue is empty!");
    }
        
    return heap[0].data;
}

template <typename T>
bool PriorityQueue<T>::isEmpty() const {
    return heap.empty();
}

template <typename T>
bool PriorityQueue<T>::isFull() const {
    return heap.size() >= 100; // arbitrary size
}

template <typename T>
void PriorityQueue<T>::clear() {
    heap.clear();
}

template <typename T>
void PriorityQueue<T>::print_queue() const {
    vector<Node> copy = heap; // copy

    int size = copy.size();
    while (size > 0) {
        const Node& top = copy[0];
        cout << "(" << top.data << ", priority=" << top.priority << ") ";

        copy[0] = copy[size - 1];
        size--;

        heapifyDownAt(copy, 0, size);
    }

    cout << endl;
}
