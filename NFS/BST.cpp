#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = right = NULL;
    }
};

class BST {
private:
    TreeNode* root;

    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == NULL)
            return new TreeNode(value);

        if (value < node->data)
            node->left = insertRecursive(node->left, value);
        else if (value > node->data)
            node->right = insertRecursive(node->right, value);

        return node;
    }

    void inorderRecursive(TreeNode* node) {
        if (node == NULL)
            return;

        inorderRecursive(node->left);
        cout << node->data << " ";
        inorderRecursive(node->right);
    }

    TreeNode* mirrorRecursive(TreeNode* node) {
        if (node == NULL)
            return NULL;

        TreeNode* leftMirror = mirrorRecursive(node->left);
        TreeNode* rightMirror = mirrorRecursive(node->right);

        node->left = rightMirror;
        node->right = leftMirror;

        return node;
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    void inorderTraversal() {
        inorderRecursive(root);
        cout << endl;
    }

    void mirror() {
        root = mirrorRecursive(root);
    }

    TreeNode* getRoot() {
        return root;
    }
};

int main() {
    BST tree;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }

    cout << "\nInorder traversal of original BST: ";
    tree.inorderTraversal();

    tree.mirror();

    cout << "Inorder traversal of mirror image BST: ";
    tree.inorderTraversal();

    return 0;
}
