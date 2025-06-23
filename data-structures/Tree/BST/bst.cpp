#include <iostream>

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

class BST {
private:
    Node* root;

    // Helper
    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->val) node->left = insert(node->left, val);
        else if (val > node->val) node->right = insert(node->right, val);
        // if duplicate, do nothing
        return node;
    }

    // Helper for search
    bool search(Node* node, int val) {
        if (node == nullptr) return false;
        if (val == node->val) return true;
        if (val < node->val) return search(node->left, val);
        return search(node->right, val);
    }

    // Helper for inorder traversal
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        std::cout << node->val << " ";
        inorder(node->right);
    }

    // Helper to find min node in right subtree (used in delete)
    Node* findMin(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    // Helper for delete
    Node* deleteNode(Node* node, int val) {
        if (node == nullptr) return node;

        if (val < node->val) {
            node->left = deleteNode(node->left, val);
        } else if (val > node->val) {
            node->right = deleteNode(node->right, val);
        } else {
            // Node to delete found
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                // Two children
                Node* temp = findMin(node->right);
                node->val = temp->val;
                node->right = deleteNode(node->right, temp->val);
            }
        }
        return node;
    }

    // Helper to free memory
    void freeTree(Node* node) {
        if (!node) return;
        freeTree(node->left);
        freeTree(node->right);
        delete node;
    }

public:
    BST() : root(nullptr) {}

    ~BST() {
        freeTree(root);
    }

    void insert(int val) {
        root = insert(root, val);
    }

    bool search(int val) {
        return search(root, val);
    }

    void inorder() {
        inorder(root);
        std::cout << "\n";
    }

    void deleteValue(int val) {
        root = deleteNode(root, val);
    }
};

int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    std::cout << "Inorder traversal: ";
    tree.inorder();

    std::cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << "\n";

    tree.deleteValue(50);

    std::cout << "Inorder after deleting 50: ";
    tree.inorder();

    return 0;
}