#include <iostream>
#include <vector>
#include <climits>
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

Node *solve(vector<int> &preorder, int mini, int maxi, int &index)
{
    if (index >= preorder.size()) // i jo preorder k upar traverse kar raha hai wo hi agar range k bahar chale jaaye to?
        return NULL;

    if (preorder[index] < mini || preorder[index] > maxi) // agar range mai lie nahi karta to?
        return NULL;

    Node *root = new Node(preorder[index]); // pehla value of preorder ko root bana diya
    index++;                                // move to the next index

    // left ka call kiya preko const rakhte hue, index to i ki tarah chalega but value dalenge range k basis pe
    root->left = solve(preorder, mini, root->data, index);

    // right ka call
    root->right = solve(preorder, root->data, maxi, index);

    return root;
}

Node *preordertoBST(vector<int> &preorder)
{
    int mini = INT_MIN; // corrected mini to INT_MIN
    int maxi = INT_MAX; // maxi is INT_MAX
    int i = 0;
    return solve(preorder, mini, maxi, i);
}

// Helper function to print in-order traversal of the tree (to verify BST)
void printInOrder(Node *root)
{
    if (root == NULL)
        return;

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

// Driver code
int main()
{
    // Example preorder sequence
    vector<int> preorder = {10, 5, 1, 7, 15, 12, 20};

    // Convert preorder to BST
    Node *root = preordertoBST(preorder);

    // Print in-order traversal of the BST
    cout << "In-order traversal of constructed BST: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
