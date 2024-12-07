#include <iostream>
#include <climits>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isBST(Node* root, int min, int max) {
    if (root == NULL) // Agar root NULL hai, to yeh valid BST hai
        return true;

    // Check if the current node lies within the min and max range
    if (root->data > min && root->data < max) {
        // Recursively check for left and right subtrees
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    } else {
        return false; // Node value is outside the range
    }
}

bool validateBST(Node* root) {
    return isBST(root, INT_MIN, INT_MAX);
}

// Helper function to insert nodes into a BST
Node* insertBST(Node* root, int value) {
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insertBST(root->left, value);
    else
        root->right = insertBST(root->right, value);

    return root;
}

// Driver code
int main() {
    Node* root = NULL;
    root = insertBST(root, 10);
    root = insertBST(root, 5);
    root = insertBST(root, 15);
    root = insertBST(root, 3);
    root = insertBST(root, 7);
    root = insertBST(root, 12);
    root = insertBST(root, 18);

    if (validateBST(root))
        cout << "The tree is a valid BST." << endl;
    else
        cout << "The tree is NOT a valid BST." << endl;

    return 0;
}
