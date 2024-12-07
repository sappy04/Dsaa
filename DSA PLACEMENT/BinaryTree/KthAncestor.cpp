#include <iostream>
using namespace std;

// Structure of a tree node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Recursive function to find the kth ancestor of a given node
Node *solve(Node *root, int &k, int node)
{
    // Base case: if the tree is empty
    if (root == NULL)
    {
        return NULL;
    }

   
    if (root->data == node)//agar ek hi node hai aur wo hi node ka ansector nikalan ahai to then to panga hai
    {
        return root;
    }

   
    Node *leftAns = solve(root->left, k, node);//left aur right traverse karne k liye..ismai hi ans store hoga
    Node *rightAns = solve(root->right, k, node);

    
    if (leftAns != NULL || rightAns != NULL)//left ya right mai mujhe node mil gaya hai then
    {//ye step baar baar chalega as mai ans upar waale node mai bhejta hoon
        k--; // k ko -- karo to go the kth ancestor
        if (k == 0)//matlab pohuch gaya bhai ancestor tak
        {
            
            k = INT_MAX; // Prevent further updates once ancestor is found
            return root;//return kar diya anscestor ko
        }
        
        return leftAns != NULL ? leftAns : rightAns;//agar left subtree se answer aa raha hai to left ka ans ek ek karke upar bhejte raho aur agar right se then right.
    }

    return NULL; // If neither subtree contains the target node
}

// Function to find the kth ancestor of a node
int kthAncestor(Node *root, int k, int node)
{
    Node *ancestor = solve(root, k, node);
    if (ancestor == NULL || ancestor->data == node)//agar bas only root hai tree mai aur wohi node ka ancestor niklane bolle then no answer bhai 
    {
        return -1; // No kth ancestor exists
    }
    return ancestor->data;
}

// Helper function to build a binary tree
Node *buildTree()
{
    int val;
    cin >> val;
    if (val == -1)
        return NULL; // Use -1 to denote NULL nodes

    Node *root = new Node(val);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

// Driver code
int main()
{
    cout << "Enter tree in preorder (use -1 for NULL):" << endl;
    Node *root = buildTree();

    int k, node;
    cout << "Enter the value of k and the target node: ";
    cin >> k >> node;

    int result = kthAncestor(root, k, node);
    if (result == -1)
    {
        cout << "No " << k << "th ancestor exists for node " << node << "." << endl;
    }
    else
    {
        cout << k << "th ancestor of node " << node << " is: " << result << endl;
    }

    return 0;
}
