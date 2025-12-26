#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

Node* insertBST(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->val) root->left = insertBST(root->left, x);
    else root->right = insertBST(root->right, x);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void preorder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main() {
    vector<int> vals = {5, 3, 7, 2, 4, 6, 8};
    Node* root = nullptr;
    for (int x : vals) root = insertBST(root, x);

    cout << "Inorder: "; inorder(root); cout << "\n";
    cout << "Preorder: "; preorder(root); cout << "\n";
    cout << "Postorder: "; postorder(root); cout << "\n";
}