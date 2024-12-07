#include <iostream>
#include <vector>
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

// ascending order mai tree ko return karta hai (rule)
void inordered(Node *root, vector<int> &inorderval)
{
    if (root == NULL)
        return;

    inordered(root->left, inorderval);
    inorderval.push_back(root->data);
    inordered(root->right, inorderval);
}

Node *flattern(Node *root)
{
    vector<int> inorderval;
    // store inorder values in sorted order
    inordered(root, inorderval);
    int n = inorderval.size();
    Node *newroot = new Node(inorderval[0]); // inorder k pehle value ko store kar liya
    Node *curr = newroot;                    // is pehle inorder value ko current mark kar diya
    // 2nd step
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(inorderval[i]); // current k baad ka value uthake set kiya temp mai
        curr->left = NULL;                    // current k left ka value ko set kiya
        curr->right = temp;                   // current k right k value ko set kar diya current k baad wala element pe
        curr = temp;                          // current ko update kar diya
    }
    curr->left = NULL;  // last node k left = null set kiya
    curr->right = NULL; // same as above acc to question

    return newroot;
}

// Helper function to print the flattened tree
void printFlattenedTree(Node *root)
{
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

// Driver code
int main()
{
    // Example tree
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    // Flatten the tree
    Node *flattenedRoot = flattern(root);

    // Print the flattened tree
    printFlattenedTree(flattenedRoot);

    return 0;
}
