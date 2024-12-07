#include <iostream>
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

// Function to find the Lowest Common Ancestor in a BST
Node* lcainBST(Node* root, Node* pre, Node* sucess) {
    if (root == NULL)
        return NULL;

    // If both nodes are greater than root, LCA lies in the right subtree
    if (root->data < pre->data && root->data < sucess->data)
        return lcainBST(root->right, pre, sucess);

    // If both nodes are smaller than root, LCA lies in the left subtree
    if (root->data > pre->data && root->data > sucess->data)
        return lcainBST(root->left, pre, sucess);

    // If one node is on the left and the other is on the right, root is the LCA
    return root;
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

    // Construct the BST
    root = insertBST(root, 20);
    root = insertBST(root, 8);
    root = insertBST(root, 22);
    root = insertBST(root, 4);
    root = insertBST(root, 12);
    root = insertBST(root, 10);
    root = insertBST(root, 14);

    // Nodes for which to find the LCA
    Node* pre = root->left->right->left; // Node with value 10
    Node* sucess = root->left->right->right; // Node with value 14

    Node* lca = lcainBST(root, pre, sucess);

    if (lca != NULL)
        cout << "The Lowest Common Ancestor of " << pre->data << " and " << sucess->data
             << " is: " << lca->data << endl;
    else
        cout << "No LCA found." << endl;

    return 0;
}
