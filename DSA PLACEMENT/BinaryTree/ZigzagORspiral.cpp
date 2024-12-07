#include <iostream>
#include <vector>
#include <queue>
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

// Function to perform ZigZag Traversal
vector<int> zigZagTraversal(Node *root)
{
    vector<int> result; // To store the final zigzag traversal
    if (root == NULL)   // If the tree is empty
        return result;

    queue<Node *> q;         // Queue for level order traversal
    q.push(root);            // root ko push kar diya
    bool leftToRight = true; // Direction flag: true = left-to-right, false = right-to-left,indexbhi iske liye 0 se start hoga

    while (!q.empty())
    {
        int size = q.size();     // for printing the no of elements in queue
        vector<int> level(size); // Temporary vector to store the current level

        // Process each node in the current level
        for (int i = 0; i < size; i++)
        {
            Node *currentNode = q.front(); // Get the front node
            q.pop();

            int index = leftToRight ? i : size - 1 - i; // agar flag true hai then l->r else r->l;
            level[index] = currentNode->data;           // answer mai nodes daal diya(queue ka  pehla element dal gaya)ye ek aisa queue hai jo ki size of the queue k equal hai aur har baar iski newly indexing hoti hai

            // Push the left and right children into the queue
            if (currentNode->left)
                q.push(currentNode->left);
            if (currentNode->right)
                q.push(currentNode->right);
        }

        // Add the current level to the result
        for (int i = 0; i < level.size(); i++)
            result.push_back(level[i]);

        // Toggle the flag
        leftToRight = !leftToRight;
    }

    return result;
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

// Main Function to Test the ZigZag Traversal
int main()
{
    Node *root = buildSampleTree();             // Build a sample tree
    vector<int> result = zigZagTraversal(root); // Perform zigzag traversal

    cout << "ZigZag Traversal of the Binary Tree: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
