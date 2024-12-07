#include <bits/stdc++.h>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to check if two trees are identical
bool isIdentical(Node* r1, Node* r2) {
    // Base case: both trees are empty
    if (r1 == NULL && r2 == NULL) {
        return true;
    }

    // If one tree is empty and the other is not
    if (r1 == NULL || r2 == NULL) {
        return false;
    }

    // Recursive calls for left and right subtrees
    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    // Check if current node's data matches
    bool value = (r1->data == r2->data);

    // Both left and right subtrees must be identical, and current node data must match
    return left && right && value;
}

// Main function
int main() {
    // Creating the first tree
    /*
            1
           / \
          2   3
    */
    Node* r1 = new Node(1);
    r1->left = new Node(2);
    r1->right = new Node(3);

    // Creating the second tree
    /*
            1
           / \
          2   3
    */
    Node* r2 = new Node(1);
    r2->left = new Node(2);
    r2->right = new Node(3);

    // Check if the two trees are identical
    if (isIdentical(r1, r2)) {
        cout << "The trees are identical." << endl;
    } else {
        cout << "The trees are not identical." << endl;
    }

    return 0;
}
