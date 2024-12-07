#include <iostream>
using namespace std;

// Node structure
struct Node
{
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

// Helper function to find the k-th smallest element
void kthSmallestUtil(Node *root, int &k, int &result)
{
    if (root == NULL) // Base case
        return;

    // Traverse the left subtree
    kthSmallestUtil(root->left, k, result);

    // Decrement k and check if we have reached the k-th smallest element
    k--;
    if (k == 0)
    {
        result = root->data; // Store the result
        return;
    }

    // Traverse the right subtree
    kthSmallestUtil(root->right, k, result);
}

int kthSmallest(Node *root, int k)
{
    int result = -1; // Initialize result
    kthSmallestUtil(root, k, result);
    return result; // Return the k-th smallest element
}

// Helper function to insert nodes into a BST
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

// Driver code
int main()
{
    Node *root = NULL;

    // Insert elements into the BST
    root = insertBST(root, 10);
    root = insertBST(root, 5);
    root = insertBST(root, 15);
    root = insertBST(root, 3);
    root = insertBST(root, 7);
    root = insertBST(root, 12);
    root = insertBST(root, 18);

    int k = 3; // Find the 3rd smallest element
    int result = kthSmallest(root, k);
    if (result != -1)
        cout << "The " << k << "-th smallest element in the BST is: " << result << endl;
    else
        cout << "The BST has fewer than " << k << " elements." << endl;

    return 0;
}
