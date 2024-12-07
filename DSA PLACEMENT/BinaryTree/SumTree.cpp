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

// Helper function to check if the tree is a Sum Tree
pair<bool, int> isSumTreeFast(Node* root) {
    // Base case: if the root is NULL, it's a Sum Tree with sum 0
    if (root == NULL) {
        return {true, 0};
    }

    // Base case: if the node is a leaf node, it's a Sum Tree with its own value as the sum
    if (root->left == NULL && root->right == NULL) {
        return {true, root->data};
    }

    // Recursive calls for left and right subtrees
    pair<bool, int> leftAns = isSumTreeFast(root->left);
    pair<bool, int> rightAns = isSumTreeFast(root->right);

    // Check if left and right subtrees are Sum Trees
    bool left = leftAns.first;
    bool right = rightAns.first;

    // Condition for the current node: root->data should equal the sum of left and right subtrees
    bool condn = (root->data == leftAns.second + rightAns.second);

    // Final result for the current node
    pair<bool, int> ans;
    ans.first = left && right && condn;
    ans.second = root->data + leftAns.second + rightAns.second;

    return ans;
}

// Function to check if the binary tree is a Sum Tree
bool isSumTree(Node* root) {
    return isSumTreeFast(root).first;
}

// Main function to test the code
int main() {
    /*
        Example Tree:
                26
              /    \
             10     3
            /  \      \
           4    6      3
    */
    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    if (isSumTree(root)) {
        cout << "The tree is a Sum Tree." << endl;
    } else {
        cout << "The tree is not a Sum Tree." << endl;
    }

    return 0;
}
