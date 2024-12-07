#include<bits/stdc++.h>
using namespace std;

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

class Solution {
    public:
    // Helper function to calculate the diameter
    pair<int, int> diameterFast(Node* root) {
        // Base case: if the root is NULL, diameter and height are 0
        if (root == NULL) {
            return {0, 0}; // {diameter, height}
        }

        // Recursive calls for left and right subtrees
        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);

        // Diameter through the current node
        int op1 = left.first; // Diameter of the left subtree
        int op2 = right.first; // Diameter of the right subtree
        int op3 = left.second + right.second + 1; // Diameter through the root

        // Calculate the final diameter and height
        int diameter = max(op1, max(op2, op3));
        int height = max(left.second, right.second) + 1;

        return {diameter, height};
    }

    // Function to return the diameter of the binary tree
    int diameter(Node* root) {
        return diameterFast(root).first; // Only the diameter part is required
    }
};

int main() {
    // Creating a sample binary tree
    /*
          1
         / \
        2   3
       / \
      4   5
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution solution;
    int treeDiameter = solution.diameter(root);

    cout << "Diameter of the binary tree: " << treeDiameter << endl;

    return 0;
}
