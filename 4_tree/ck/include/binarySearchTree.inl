
// Constructor
template <typename T>
BST<T>::BST() 
: root(nullptr) {

}

// Destructor
template <typename T>
BST<T>::~BST() {
    clear();
}

template <typename T>
typename BST<T>::Node* BST<T>::getRoot() const{
    return root;
}

// // Private insert function (recursive) // error occurs 
// study why error occurs
// template <typename T>
// bool BST<T>::insert(typename BST<T>::Node* node, T value) {
//     if (!node) { // node == nullptr
//         std::cout << "1\n";
//         node = new Node(value);
//         std::cout << node->data << std::endl;
//         std::cout << getRoot()->data;
//         return true;
//     }
//     if (value < node->data) {
//         return insert(node->left, value);
//     }
//     else if (value > node->data) {
//         return insert(node->right, value);
//     }
//     return false;  // ❌ Value already exists
// }

// Public insert function
template <typename T>
bool BST<T>::insert(T value) {
    
    Node* newNode = new Node(value);

    if (!root) {
        root = newNode;
        return true;
    }

    Node* current = root;
    Node* parent = nullptr;

    while (current) {        
        parent = current;

        if (value < current->data) {
            current = current->left;
        } else if (value > current->data) {
            current = current->right;
        } else {
            // Value already exists, don't insert duplicate
            delete newNode;
            return false;
        }
    }

    // Attach the new node to the correct position
    if (value < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return true;
}

// Private findMin function
template <typename T>
typename BST<T>::Node* BST<T>::findMin(typename BST<T>::Node* node) {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

// Public findMin function
template <typename T>
T BST<T>::findMin() const {
    return root ? findMin(root)->data : T();
}

// Public findMax function
template <typename T>
T BST<T>::findMax() const {
    typename BST<T>::Node* node = root;
    while (node && node->right) {
        node = node->right;
    }
    return node ? node->data : T();
}

// This doesnt work either
// // Private delete function (recursive)
// template <typename T>
// bool BST<T>::deleteNode(typename BST<T>::Node* node, T value) {
//     if (!node) { // node == nullptr
//         return false;
//         // return nullptr;
//     }
//     if (value < node->data) {
//         // node->left = deleteNode(node->left, value);
//         return deleteNode(node->left, value);
//     }
//     else if (value > node->data) {
//         // node->right = deleteNode(node->right, value);
//         return deleteNode(node->right, value);
//     }
//     else { // value == node->data
//         if (!node->left) { // node->left == nullptr // no left child then replace it with the right child
//             typename BST<T>::Node* temp = node->right;
//             delete node;
//             node = temp;
//         } else if (!node->right) { // node->right == nullptr // no right child then replace it with the left child
//             typename BST<T>::Node* temp = node->left;
//             delete node;
//             node = temp;
//         }
//         else{
//             typename BST<T>::Node* temp = findMin(node->right); // find the smallest node and replace it with the deleting node
//             node->data = temp->data;
//             return deleteNode(node->right, temp->data);

//         }
//     }
//     return true;
// }

// Public delete function
template <typename T>
bool BST<T>::deleteValue(T value) {
    Node* current = root;
    Node* parent = nullptr;

    // Step 1: Find the node to delete and its parent
    while (current && current->data != value) {
        parent = current;
        if (value < current->data){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }

    if (!current){
        return false;  // Value not found
    } 

    // Step 2: Node has two children
    if (current->left && current->right) {
        // Find in-order successor (smallest in right subtree)
        Node* successorParent = current;
        Node* successor = current->right;
        while (successor->left) {
            successorParent = successor;
            successor = successor->left;
        }

        // Replace current's data with successor's data
        current->data = successor->data;

        // Now delete the successor instead
        current = successor;
        parent = successorParent;
    }

    // Step 3: Node has 0 or 1 child
    if (current->left == nullptr && current->right == nullptr) {
        // Case 1: Leaf node (no children)
        if (!parent) { // if this case, we are deleting the root.
            root = nullptr;  // Deleting the root node
        } else if (parent->left == current) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
    }    
    else if (current->left == nullptr || current->right == nullptr) {
        // Case 2: Only one child
        Node* child = nullptr;
        if (current->left != nullptr) {
            child = current->left;
        } else if (current->right != nullptr) {
            child = current->right;
        } else {
            child = nullptr;  // 둘 다 없으면 null (leaf node)
        }

        if (!parent) {
            root = child;
        } else if (parent->left == current) {
            parent->left = child;
        } else {
            parent->right = child;
        }
    }
    delete current;
    return true;
}
// Private search function (recursive)
template <typename T>
bool BST<T>::search(typename BST<T>::Node* node, T value) const {
    if (!node) {
        return false;
    }
    if (node->data == value) {
        return true;
    }
    return value < node->data ? search(node->left, value) : search(node->right, value);
}

// Public search function
template <typename T>
bool BST<T>::search(T value) const {
    return search(root, value);
}

// Private inorder traversal
template <typename T>
void BST<T>::inorder(typename BST<T>::Node* node) const {
    if (!node) {
        return;
    }
    inorder(node->left);
    std::cout << node->data << " "; // this could be tricky for template data
    inorder(node->right);
}

// Public inorder traversal
template <typename T>
void BST<T>::inorder() const {
    inorder(root);
    std::cout << std::endl; 
}

// Private preorder traversal
template <typename T>
void BST<T>::preorder(Node* node) const {
    if (!node) {
        return;
    }
    // printf("\tI am here\n");
    cout << node->data << endl;
    preorder(node->left);
    preorder(node->right);
}

template <typename T>
// Public preorder traversal
void BST<T>::preorder() const {
    preorder(root);
    cout << endl;
}



// Private postorder traversal
template <typename T>
void BST<T>::postorder(Node* node) const {
    if (!node) {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " "; // this could be tricky for template data
}

template <typename T>
// Public postorder traversal
void BST<T>::postorder () const {
    postorder(root);
    cout << endl;
}

// Private function to calculate height
template <typename T>
int BST<T>::getHeight(typename BST<T>::Node* node) const {
    if (!node) return 0;
    return 1 + std::max(getHeight(node->left), getHeight(node->right));
}

// Public function to get height
template <typename T>
int BST<T>::getHeight() const {
    return getHeight(root);
}

// Check if the tree is empty
template <typename T>
bool BST<T>::isEmpty(typename BST<T>::Node* node) const {
    return node == nullptr;
}

template <typename T>
bool BST<T>::isEmpty() const {
    return root == nullptr;
}

// Private function to clear the tree
template <typename T>
void BST<T>::clear(typename BST<T>::Node*& node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
    node = nullptr;
}

// Public function to clear the tree
template <typename T>
void BST<T>::clear() {
    clear(root);
}

template <typename T>
void BST<T>::print_tree() {
    preorder();
}






// // Private delete function (recursive)
// BST::Node* BST::deleteNode(Node* node, int value) {
//     if (!node){
//         return nullptr;
//     }
//     if (value < node->data) {
//         node->left = deleteNode(node->left, value);
//     }
//     else if (value > node->data){
//         node->right = deleteNode(node->right, value);
//     }
//     else {
//         if (!node->left) { // if node->left == nullptr
//             Node* temp = node->right;
//             delete node;
//             return temp;
//         } else if (!node->right) {
//             Node* temp = node->left;
//             delete node;
//             return temp;
//         }
//         Node* temp = findMin(node->right);
//         node->data = temp->data;
//         node->right = deleteNode(node->right, temp->data);
//     }
//     return node;
// }

// // Public delete function
// void BST::deleteValue(int value) {
//     root = deleteNode(root, value);
// }

// // Private findMin function
// BST::Node* BST::findMin(Node* node) {
//     while (node && node->left) node = node->left;
//     return node;
// }

// // Public findMin function
// int BST::findMin() const {
//     return root ? findMin(root)->data : -1;
// }