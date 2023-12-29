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

    // Menghapus data 40 dari tree
    tree.remove(40);

    // Menampilkan hasil Inorder Traversal setelah penghapusan
    tree.inorderTraversal();

    return 0;
}