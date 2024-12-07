#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Info
{
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

Info solve(Node *root, int &ans)
{
    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0}; // base case
    }

    Info left = solve(root->left, ans); // traversal sideways
    Info right = solve(root->right, ans);

    Info currentNode;
    currentNode.size = left.size + right.size + 1;  // left + right + root => for the root
    currentNode.maxi = max(root->data, right.maxi); // max value hamesha right subtree se hi ata hai
    currentNode.mini = min(root->data, left.mini);  // min value hamesha left subtree se ata hai

    // check for bst (basic condition)
    if (left.isBST && right.isBST && (left.maxi < root->data) && (root->data < right.mini))
    {
        currentNode.isBST = true;
    }
    else
    {
        currentNode.isBST = false;
    }

    // answer ko update kiya
    if (currentNode.isBST)
    { // agar bst hi hai ans mai store kar de
        ans = max(ans, currentNode.size);
    }

    return currentNode;
}

int largestBST(Node *root)
{
    int maxsize = 0;
    Info temp = solve(root, maxsize);
    return maxsize;
}

// Helper function to insert a node in a BST
Node *insertBST(Node *root, int value)
{
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insertBST(root->left, value);
    else
        root->right = insertBST(root->right, value);

    return root;
}

int main()
{
    // Construct a sample tree
    Node *root = NULL;
    root = insertBST(root, 10);
    root = insertBST(root, 5);
    root = insertBST(root, 15);
    root = insertBST(root, 1);
    root = insertBST(root, 8);
    root = insertBST(root, 7);

    // Get the size of the largest BST
    cout << "The size of the largest BST is: " << largestBST(root) << endl;

    return 0;
}
