// #include "SinglyLinkedList.hpp"

// Constructor
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
: head(nullptr)
, length(0) 
{

}

// Destructor: 
template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clear();
}

// Insert an element at a specific position
template <typename T>
void SinglyLinkedList<T>::insert(int pos, T item) {
    if (pos < 0 || pos > length) {
        std::cerr << "Invalid position!\n";
        return;
    }

    Node* newNode = new Node(item);
    
    if (pos == 0) { // Insert at head
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        for (int  ii = 0; ii < pos - 1; ++ii) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    length++;
}

// Insert at the end
template <typename T>
void SinglyLinkedList<T>::insert_last(T item) {
    insert(length, item);
}

// Insert at the beginning
template <typename T>
void SinglyLinkedList<T>::insert_first(T item) {
    insert(0, item);
}

// Delete an element at a specific position
template <typename T>
void SinglyLinkedList<T>::delete_at(int pos) {
    if (pos < 0 || pos >= length || is_empty()) {
        std::cerr << "Invalid position or empty list!\n";
        return;
    }

    Node* temp = head;
    if (pos == 0) {
        head = head->next;
        delete temp;
    } else {
        Node* prev = nullptr;
        for (int i = 0; i < pos; ++i) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
    }

    length--;
}

// Clear the entire list
template <typename T>
void SinglyLinkedList<T>::clear() {
    while (!is_empty()) {
        delete_at(0);
    }
}

// Get the entry at a specific position
template <typename T>
T SinglyLinkedList<T>::get_entry(int pos) {
    if (pos < 0 || pos >= length) {
        throw std::out_of_range("Invalid position!");
    }

    Node* temp = head;
    for (int i = 0; i < pos; ++i) {
        temp = temp->next;
    }
    return temp->data;
}

// Get the length of the list
template <typename T>
const int SinglyLinkedList<T>::get_length() {
    return length;
}

// Check if the list is empty
template <typename T>
bool SinglyLinkedList<T>::is_empty() {
    return length == 0;
}

// Print all elements in the list
template <typename T>
void SinglyLinkedList<T>::print_list() {
    Node* temp = head;
    std::cout << "List: ";
    while (temp) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}
