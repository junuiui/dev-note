// tree (general)

#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    std::vector<TreeNode*> children;

    TreeNode(int val) : val(val) {}

    ~TreeNode() {
        for (TreeNode *child : children) {
            delete child;
        }
    }
};

// Preorder traversal: root → children
void printTree(TreeNode* node, int depth = 0) {
    if (!node) return;

    std::string indent(depth * 2, ' ');
    std::cout << indent << "- " << node->val << "\n";

    for (TreeNode* child : node->children) {
        printTree(child, depth + 1);
    }
}

int main() {
    // Constructing a general tree:
    //          1
    //        / | \
    //       2  3  4
    //          |
    //          5
    TreeNode* root = new TreeNode(1);
    TreeNode* child2 = new TreeNode(2);
    TreeNode* child3 = new TreeNode(3);
    TreeNode* child4 = new TreeNode(4);
    TreeNode* child5 = new TreeNode(5);

    child3->children.push_back(child5);
    root->children.push_back(child2);
    root->children.push_back(child3);
    root->children.push_back(child4);

    std::cout << "General Tree Structure:\n";
    printTree(root);

    // Clean up memory
    delete root;

    return 0;
}
