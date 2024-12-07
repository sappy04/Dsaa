#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;  // Initialize left as NULL
        this->right = NULL; // Initialize right as NULL
    }
};

// Function to traverse the tree and count leaf nodes
void inorder(Node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, count); // Traverse the left subtree

    if (root->left == NULL && root->right == NULL) // Check if it's a leaf node
    {
        count++;
    }

    inorder(root->right, count); // Traverse the right subtree
}

// Function to count the number of leaf nodes
int noofleafnode(Node *root)
{
    int count = 0;
    inorder(root, count);
    return count;
}

// Function to build a tree (for testing purposes)
Node *buildtree()
{
    cout << "Enter the data: ";
    int data;
    cin >> data;

    if (data == -1) // Base case: if data is -1, return NULL
    {
        return NULL;
    }

    Node *root = new Node(data); // Create a new node

    cout << "Enter data for the left child of " << data << ": ";
    root->left = buildtree();

    cout << "Enter data for the right child of " << data << ": ";
    root->right = buildtree();

    return root;
}

// Main function
int main()
{
    Node *root = NULL;

    // Build tree from user input
    root = buildtree();

    // Count the number of leaf nodes
    int leafNodeCount = noofleafnode(root);

    cout << "Number of leaf nodes: " << leafNodeCount << endl;

    return 0;
}
