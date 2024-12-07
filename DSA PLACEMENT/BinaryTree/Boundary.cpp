#include <iostream>
#include <vector>
using namespace std;

// Definition of a Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    { // Constructor to create a new node
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to traverse the left boundary
void traverseLeft(Node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))//agar tree hi khali hai ya ek hi node hai jiske koi child nahi
        return; //khattam karo

    ans.push_back(root->data); // Store the current node

    if (root->left) //agar root ka left mai lefthai to left jaate raho 
        traverseLeft(root->left, ans);//root k left mai aajte jaa rahe aur store karte jaa rahe ans mai
    else //agar koi asia scene hua ki root ka left null hua to 
        traverseLeft(root->right, ans);//right mai gaya dekha left hai kya?agar nahi hai to isse node k right pe check kar,agar nahi hai to include karle
}

// Function to traverse the leaf nodes
void traverseLeaf(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return; // Base case: Skip null nodes

    if (root->left == NULL && root->right == NULL)
    { // Leaf node condition
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);  // Traverse the left subtree
    traverseLeaf(root->right, ans); // Traverse the right subtree
}

// Function to traverse the right boundary
void traverseRight(Node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return; // Base case: Skip null or leaf nodes

    if (root->right) // Prioritize right child
        traverseRight(root->right, ans);
    else // If right is absent, go to the left child
        traverseRight(root->left, ans);

    ans.push_back(root->data); // Add the node while coming back
}

// Function to perform Boundary Traversal
vector<int> boundaryTraversal(Node *root)
{
    vector<int> ans;

    if (root == NULL)
        return ans; // If the tree is empty, return an empty vector

    ans.push_back(root->data); // Add root data

    // Traverse the left boundary (excluding root and leaf nodes)
    traverseLeft(root->left, ans);

    // Traverse all leaf nodes (both left and right subtrees)
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);

    // Traverse the right boundary (excluding root and leaf nodes)
    vector<int> rightBoundary; // Temporary vector to hold the right boundary
    traverseRight(root->right, rightBoundary);
    ans.insert(ans.end(), rightBoundary.rbegin(), rightBoundary.rend()); // Add in reverse order

    return ans;
}

// Helper Function to Build a Simple Tree for Testing
Node *buildSampleTree()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

// Main Function to Test the Boundary Traversal
int main()
{
    Node *root = buildSampleTree();               // Build a sample tree
    vector<int> result = boundaryTraversal(root); // Perform boundary traversal

    cout << "Boundary Traversal of the Binary Tree: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
