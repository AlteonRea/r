// Doubly Circular Link List
#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyCircularLinkedList {
public:
    Node* head;

    DoublyCircularLinkedList() : head(nullptr) {}

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void display() {
        if (head == nullptr) {
            std::cout << "Doubly Circular Linked List is empty." << std::endl;
            return;
        }

        Node* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }

    void deleteData(int value) {
        if (head == nullptr) {
            std::cout << "Doubly Circular Linked List is empty. Cannot delete." << std::endl;
            return;
        }

        Node* current = head;
        do {
            if (current->data == value) {
                // Node with the desired value found, delete it
                if (current == head) {
                    // If the node is the head, update head
                    head = current->next;
                }
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                std::cout << "Deleted " << value << " from the list." << std::endl;
                return;
            }
            current = current->next;
        } while (current != head);

        // The value was not found in the list
        std::cout << "Value " << value << " not found in the list. Cannot delete." << std::endl;
    }
};

int main() {
    DoublyCircularLinkedList myDoublyCircularList;
    myDoublyCircularList.append(1);
    myDoublyCircularList.append(2);
    myDoublyCircularList.append(3);

    std::cout << "Doubly Circular Linked List: ";
    myDoublyCircularList.display();

    myDoublyCircularList.deleteData(2);

    std::cout << "After deletion: ";
    myDoublyCircularList.display();

    return 0;
}

// Static Array Stack
#include <iostream>

const int MAX_SIZE = 100; // Maximum size of the stack

class Stack {
private:
    int elements[MAX_SIZE];
    int topIndex; // Index of the top element

public:
    // Constructor
    Stack() : topIndex(-1) {}

    // Function to push an element onto the stack
    void push(int value) {
        if (topIndex < MAX_SIZE - 1) {
            elements[++topIndex] = value;
        } else {
            std::cout << "Stack overflow. Cannot push." << std::endl;
        }
    }

    // Function to pop an element from the stack
    void pop() {
        if (!isEmpty()) {
            --topIndex;
        } else {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
        }
    }

    // Function to get the top element of the stack
    int top() const {
        if (!isEmpty()) {
            return elements[topIndex];
        } else {
            std::cerr << "Stack is empty. Cannot get top element." << std::endl;
            return -1; // Return a default value indicating an empty stack
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() const {
        return topIndex == -1;
    }

    // Function to display the elements of the stack
    void display() const {
        if (!isEmpty()) {
            std::cout << "Stack: ";
            for (int i = 0; i <= topIndex; ++i) {
                std::cout << elements[i] << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "Stack is empty." << std::endl;
        }
    }
};

int main() {
    // Create a stack and perform some operations
    Stack myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    myStack.display();

    std::cout << "Top element: " << myStack.top() << std::endl;

    myStack.pop();
    myStack.display();

    return 0;
}


// Doubly Circular Combined Stack
#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class CircularDoublyLinkedListStack {
private:
    Node* top;

public:
    CircularDoublyLinkedListStack() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node(value);
        if (top != nullptr) {
            newNode->prev = top;
            newNode->next = top->next;
            top->next->prev = newNode;
            top->next = newNode;
            top = newNode;
        } else {
            newNode->prev = newNode;
            newNode->next = newNode;
            top = newNode;
        }
    }

    void pop() {
        if (top != nullptr) {
            Node* temp = top;
            top->prev->next = top->next;
            top->next->prev = top->prev;

            if (top->next == top) {
                // Last element in the list
                top = nullptr;
            } else {
                top = top->prev;
            }

            delete temp;
        } else {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
        }
    }

    int topValue() const {
        if (top != nullptr) {
            return top->data;
        } else {
            std::cerr << "Stack is empty. Cannot get top value." << std::endl;
            return -1; // Return a default value indicating an empty stack
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    void displayAll() const {
        Node* current = top;
        if (current == nullptr) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }

        do {
            std::cout << current->data << " ";
            current = current->prev; // Traverse backward in the circular doubly linked list
        } while (current != top);

        std::cout << std::endl;
    }

};

int main() {
    CircularDoublyLinkedListStack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Display all elements: ";
    stack.displayAll();

    return 0;
}


// Doubly Circular Link List Queue (No Priority)
#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class CircularDoublyLinkedListQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularDoublyLinkedListQueue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front; // Make it circular
            front->prev = rear; // Make it doubly linked
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
            rear->next = front; // Make it circular
            front->prev = rear; // Make it doubly linked
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            Node* temp = front;
            if (front == rear) {
                front = rear = nullptr; // Queue has only one element
            } else {
                front = front->next;
                rear->next = front; // Maintain circular structure
                front->prev = rear; // Maintain doubly linked structure
            }
            delete temp;
        } else {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        }
    }

    void display() const {
        if (!isEmpty()) {
            std::cout << "Queue: ";
            Node* current = front;
            do {
                std::cout << current->data << " ";
                current = current->next;
            } while (current != front);
            std::cout << std::endl;
        } else {
            std::cout << "Queue is empty." << std::endl;
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }
};

int main() {
    CircularDoublyLinkedListQueue circularDoublyQueue;

    circularDoublyQueue.enqueue(1);
    circularDoublyQueue.enqueue(2);
    circularDoublyQueue.enqueue(3);

    circularDoublyQueue.display();

    circularDoublyQueue.dequeue();
    circularDoublyQueue.display();

    return 0;
}

// Doubly Circular Link List Queue (Priority)
#include <iostream>

class Node {
public:
    int data;
    int priority;
    Node* next;
    Node* prev;

    Node(int value, int prio) : data(value), priority(prio), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedListQueue {
private:
    Node* front;
    Node* rear;

public:
    DoublyLinkedListQueue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value, int priority) {
        Node* newNode = new Node(value, priority);
        if (isEmpty()) {
            front = rear = newNode;
            front->prev = rear;
            rear->next = front;
        } else {
            Node* current = front;
            while (current->next != front && current->priority >= priority) {
                current = current->next;
            }

            if (current->priority < priority) {
                // Insert before current
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
                if (current == front) {
                    front = newNode;
                }
            } else {
                // Insert at the end
                rear->next = newNode;
                newNode->prev = rear;
                newNode->next = front;
                rear = newNode;
                front->prev = rear;
            }
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            Node* temp = front;
            if (front == rear) {
                front = rear = nullptr; // Queue has only one element
            } else {
                front = front->next;
                rear->next = front; // Maintain circular structure
                front->prev = rear; // Maintain doubly linked structure
            }
            if (temp == rear) {
                rear = nullptr; // Update rear if needed
            }
            delete temp;
        } else {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        }
    }



    void display() const {
        if (!isEmpty()) {
            std::cout << "Queue: ";
            Node* current = front;
            do {
                std::cout << "(" << current->data << ", " << current->priority << ") ";
                current = current->next;
            } while (current != front);
            std::cout << std::endl;
        } else {
            std::cout << "Queue is empty." << std::endl;
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }
};

int main() {
    DoublyLinkedListQueue doublyQueue;

    doublyQueue.enqueue(1, 2);
    doublyQueue.enqueue(2, 1);
    doublyQueue.enqueue(3, 3);

    doublyQueue.display();

    doublyQueue.dequeue();
    doublyQueue.display();

    doublyQueue.dequeue();
    doublyQueue.display();

    doublyQueue.dequeue();
    doublyQueue.display();

    return 0;
}

// Tree
#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    // Helper function to insert a value into the BST
    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    // Helper function to perform an inorder traversal
    void inorderTraversal(TreeNode* node) const {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // Function to insert a value into the BST
    void insert(int value) {
        root = insert(root, value);
    }

    // Function to perform an inorder traversal of the BST
    void inorderTraversal() const {
        std::cout << "Inorder Traversal: ";
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree bst;

    // Insert values into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Perform inorder traversal
    bst.inorderTraversal();

    return 0;
}

// AVL Tree
#include <iostream>
#include <algorithm>

class AVLNode {
public:
    int data;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(int value) : data(value), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    AVLNode* root;

    // Helper function to get the height of a node
    int getHeight(AVLNode* node) const {
        return (node != nullptr) ? node->height : 0;
    }

    // Helper function to calculate the balance factor of a node
    int getBalanceFactor(AVLNode* node) const {
        return (node != nullptr) ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    // Helper function to update the height of a node
    void updateHeight(AVLNode* node) {
        if (node != nullptr) {
            node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        }
    }

    // Helper function for right rotation
    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        updateHeight(y);
        updateHeight(x);

        return x;
    }

    // Helper function for left rotation
    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        updateHeight(x);
        updateHeight(y);

        return y;
    }

    // Helper function to balance the tree
    AVLNode* balance(AVLNode* node) {   
        // Update height of current node
        updateHeight(node);

        // Get balance factor
        int balanceFactor = getBalanceFactor(node);

        // Left Heavy
        if (balanceFactor > 1) {
            if (getBalanceFactor(node->left) >= 0) {
                // Left Left Case
                return rightRotate(node);
            } else {
                // Left Right Case
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }

        // Right Heavy
        if (balanceFactor < -1) {
            if (getBalanceFactor(node->right) <= 0) {
                // Right Right Case
                return leftRotate(node);
            } else {
                // Right Left Case
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }

        return node; // No rotation needed
    }

    // Helper function to insert a value into the AVL tree
    AVLNode* insert(AVLNode* node, int value) {
        // Perform standard BST insert
        if (node == nullptr) {
            return new AVLNode(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        } else {
            // Duplicate values are not allowed
            return node;
        }

        // Update height of current node
        updateHeight(node);

        // Balance the tree
        return balance(node);
    }

    // Helper function to delete a node with a given value
    AVLNode* deleteNode(AVLNode* node, int value) {
        // Perform standard BST delete
        if (node == nullptr) {
            std::cout << "Data not found: " << value << std::endl;
            return node;
        }

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            // Node with the value to be deleted found

            // Case 1: Node with only one child or no child
            if (node->left == nullptr || node->right == nullptr) {
                AVLNode* temp = (node->left) ? node->left : node->right;

                // No child case
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    // One child case
                    *node = *temp; // Copy the contents of the non-empty child
                }

                delete temp;
            } else {
                // Case 2: Node with two children

                // Find the inorder successor (smallest node in the right subtree)
                AVLNode* temp = minValueNode(node->right);

                // Copy the inorder successor's data to this node
                node->data = temp->data;

                // Delete the inorder successor
                node->right = deleteNode(node->right, temp->data);
            }
        }

        // If the tree had only one node, then return
        if (node == nullptr) {
            return node;
        }

        // Update height of the current node
        updateHeight(node);

        // Balance the tree
        return balance(node);
    }

    // Helper function to find the node with the smallest value in a subtree
    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Helper function to perform an inorder traversal
    void inorderTraversal(AVLNode* node) const {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    // Function to insert a value into the AVL tree
    void insert(int value) {
        root = insert(root, value);
    }

    // Function to delete a value from the AVL tree
    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    // Function to perform an inorder traversal of the AVL tree
    void inorderTraversal() const {
        std::cout << "Inorder Traversal: ";
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    AVLTree avl;

    // Insert values into the AVL tree
    avl.insert(50);
    avl.insert(30);
    avl.insert(70);
    avl.insert(20);
    avl.insert(40);
    avl.insert(60);
    avl.insert(80);

    // Perform inorder traversal
    avl.inorderTraversal();

    // Delete values from the AVL tree
    avl.deleteValue(20);
    avl.deleteValue(70);
    avl.deleteValue(90);

    // Perform inorder traversal after deletion
    avl.inorderTraversal();

    return 0;
}
