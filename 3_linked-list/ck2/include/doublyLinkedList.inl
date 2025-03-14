// Constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
: head(nullptr)
, tail(nullptr)
, length(0) {

}


// Destructor: 
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

// Insert an element at a specific position
template <typename T>
void DoublyLinkedList<T>::insert(int pos, T item) {
    if (pos < 0 || pos > length) {
        std::cerr << "Invalid position!\n";
        return;
    }

    Node* newNode = new Node(item);
       
    if (pos == 0) {
        insert_front(item);
    } else if (pos == length) {
        insert_last(item);
    } else {
        Node* tmp = head;
        for (int ii = 0; ii < pos - 1; ++ii) {
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        newNode->prev = tmp;
        newNode->data = item;
        tmp->next->prev = newNode;
        tmp->next = newNode;
        length++;
    }
}

// Insert at the end
template <typename T>
void DoublyLinkedList<T>::insert_last(T item) {
    Node* newNode = new Node(item);
    newNode->data = item;
    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

// Insert at the beginning
template <typename T>
void DoublyLinkedList<T>::insert_front(T item) {
    Node* newNode = new Node(item);
    newNode->data = item;
    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    length++;
}

// Delete an element at a specific position
template <typename T>
void DoublyLinkedList<T>::delete_at(int pos) {
    if (pos < 0 || pos >= length || is_empty()) {
        std::cerr << "Invalid position or empty list!\n";
        return;
    }

    Node* tmp;
    if (pos == 0) {
        tmp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        if (tmp == tail) {
            tail = nullptr;
        }
    } else if (pos == length - 1) {
        tmp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        }
    } else {
        tmp = head;
        for (int i = 0; i < pos; ++i) {
            tmp = tmp->next;
        }
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
    }

    delete tmp;
    length--;
}

// Clear the entire list
template <typename T>
void DoublyLinkedList<T>::clear() {
    while (!is_empty()) {
        delete_at(0);
    }
}

// Get the entry at a specific position
template <typename T>
T DoublyLinkedList<T>::get_entry(int pos) {
    if (pos < 0 || pos >= length) {
        throw std::out_of_range("Invalid position!");
    }

    Node* tmp = head;
    for (int ii = 0; ii < pos; ++ii) {
        tmp = tmp->next;
    }
    return tmp->data;
}

// Get the length of the list
template <typename T>
const int DoublyLinkedList<T>::get_length() {
    return length;
}

// Check if the list is empty
template <typename T>
bool DoublyLinkedList<T>::is_empty() {
    return length == 0;
}
