#include <bits/stdc++.h>
using namespace std;

// Define the structure of a node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

int countNodes(Node *root) // exactly kitne nodes hai utna hi return kar raha hai
{
    int count;
    if (root == NULL)
    {
        count = 0;
        return count;
    }
    int ans = 1 + countNodes(root->left) + countNodes(root->right); // left ka nodes ka count kiya with right ka and main root ka(1)
    return ans;
}

// Check if the binary tree is a complete binary tree (CBT)
bool iscbt(Node *root, int index, int count) // cbt check karta hai
{
    if (root == NULL)
    {
        return true;
    } // index mai mere kitne hone chahiye tree mai utna hi return kar raha hai
    if (index > count) // agar mera index mera count function se aya hua count se badha hai then
    {
        return false;
    } // cbt nahi hai
    else                                                                // matlab index count se kam hai
    {                                                                   // yaha pe per node k index pe uske kitne bache hone chahiye nikal rahe hai by formula jo ki note ho ja raha hai
        bool leftsubtree = iscbt(root->left, (2 * index + 1), count);   // left substree ko check karo
        bool rightsubtree = iscbt(root->right, (2 * index + 2), count); // right subtree ko check karo
        return (leftsubtree && rightsubtree);
    }
}

// Check if the binary tree follows the max-heap property
bool ismax(Node *root)
{
    // agar mera root ka koi child hi nahi hua to
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    // ager mere root ka sirf left child hai
    if (root->right == NULL)
    {
        return (root->data >= root->left->data); // root ka left root se chota hai
    }
    else
    {
        bool left = ismax(root->left); // left traversal for checking is the left subtree is following the max order
        bool right = ismax(root->right);
        return (left && right && (root->data >= root->left->data && root->data >= root->right->data)); // agar left/right donno mera max order follow karta hai aur root ka data mere left and right subtree k value se badha hai to true hai
    }
}

// Check if the binary tree is a heap
bool isaheap(struct Node *root)
{
    int index = 0;                                // starting index se check kar raha hoon isliye starting index mujhe 0 hi chahiye
    int count = countNodes(root);                 // ye cbt mai help karega
    if (iscbt(root, index, count) && ismax(root)) // agar mera tree cbt and max order follow kar raha hai aur kya hi chahiye...
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Utility function to build a binary tree from user input (level order)
Node *buildTree()
{
    cout << "Enter data for the root node (-1 for no node): ";
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        cout << "Enter left child of " << current->data << " (-1 for no node): ";
        cin >> data;
        if (data != -1)
        {
            current->left = new Node(data);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->data << " (-1 for no node): ";
        cin >> data;
        if (data != -1)
        {
            current->right = new Node(data);
            q.push(current->right);
        }
    }

    return root;
}

int main()
{
    // Build the binary tree
    Node *root = buildTree();

    // Check if the binary tree is a heap
    if (isaheap(root))
    {
        cout << "The binary tree is a heap.\n";
    }
    else
    {
        cout << "The binary tree is not a heap.\n";
    }

    return 0;
}
