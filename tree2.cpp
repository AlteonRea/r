#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    void insert(TreeNode*& node, int val) {
        if (node == nullptr) {
            node = new TreeNode(val);
        } else {
            if (val < node->data) {
                insert(node->left, val);
            } else {
                insert(node->right, val);
            }
        }
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* remove(TreeNode*& node, int val) {
        if (node == nullptr) {
            return node;
        }

        if (val < node->data) {
            node->left = remove(node->left, val);
        } else if (val > node->data) {
            node->right = remove(node->right, val);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children
            TreeNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }

        return node;
    }

    void inorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    void preorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    void postorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            std::cout << node->data << " ";
        }
    }

    TreeNode* find(TreeNode* node, int val) {
        if (node == nullptr || node->data == val) {
            return node;
        }

        if (val < node->data) {
            return find(node->left, val);
        } else {
            return find(node->right, val);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int val) {
        insert(root, val);
    }

    void remove(int val) {
        root = remove(root, val);
    }

    void inorderTraversal() {
        std::cout << "Inorder Traversal: ";
        inorderTraversal(root);
        std::cout << std::endl;
    }

    void preorderTraversal() {
        std::cout << "Preorder Traversal: ";
        preorderTraversal(root);
        std::cout << std::endl;
    }

    void postorderTraversal() {
        std::cout << "Postorder Traversal: ";
        postorderTraversal(root);
        std::cout << std::endl;
    }

    TreeNode* find(int val) {
        return find(root, val);
    }
};

int main() {
    BinaryTree tree;

    // Menambahkan data ke dalam tree
    tree.insert(50);
    tree.insert(20);
    tree.insert(40);
    tree.insert(100);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    // Menampilkan hasil Inorder Traversal sebelum penghapusan
    tree.inorderTraversal();

    // Menampilkan hasil Preorder Traversal
    tree.preorderTraversal();

    // Menampilkan hasil Postorder Traversal
    tree.postorderTraversal();

    // Mencari nilai 60 dalam tree
    int valueToFind = 60;
    TreeNode* foundNode = tree.find(valueToFind);

    if (foundNode) {
        std::cout << "Value " << valueToFind << " found in the tree." << std::endl;
    } else {
        std::cout << "Value " << valueToFind << " not found in the tree." << std::endl;
    }

    // Menghapus data 40 dari tree
    tree.remove(40);

    // Menampilkan hasil Inorder Traversal setelah penghapusan
    tree.inorderTraversal();

    return 0;
}
