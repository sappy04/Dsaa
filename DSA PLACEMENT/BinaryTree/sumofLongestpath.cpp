#include <iostream>
#include <queue>
#include <climits>
using namespace std;

// Node structure for the binary tree
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

// Function to calculate the sum of the longest path
void sumofLongestpath(Node *root, int sum, int &maxsum, int len, int &maxlen)
{
    if (root == NULL)
    { // tree khali bhi ho sakta hai aur aisa bhi ho sakta hai ki root k left aur right mai kuch hai nahi
        if (len > maxlen)
        {                 // len zyada hai max len se to update karo
            maxlen = len; // updated
            maxsum = sum; // sum aur len side by side chalte hai na to donno ko update karo
        }
        else if (maxlen == len)
        {
            maxsum = max(sum, maxsum);
        }
        return;
    }
    sum += root->data;                                           // sum karta jaa raha mai node by node
    sumofLongestpath(root->left, sum, maxsum, len + 1, maxlen);  // left traversal
    sumofLongestpath(root->right, sum, maxsum, len + 1, maxlen); // right traversal, length kisi bhi taraf jao badhna to hai hi traverse karoge to
}

// Main function to solve the problem
int solve(Node *root)
{                         // root se start karenge
    int len = 0;          // length will get stored in this as we traverse down
    int maxlen = 0;       // to store the longest root length
    int sum = 0;          // to cal sum
    int maxsum = INT_MIN; // maxsum compare karega ki har root ka sum ab k root se badha hai ya chota
    sumofLongestpath(root, sum, maxsum, len, maxlen);
    return maxsum;
}

// Helper function to build the binary tree
Node *buildTree()
{
    int val;
    cin >> val;
    if (val == -1)
        return nullptr; // Use -1 to denote NULL nodes

    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal; // Input left child
        if (leftVal != -1)
        {
            current->left = new Node(leftVal);
            q.push(current->left);
        }

        cin >> rightVal; // Input right child
        if (rightVal != -1)
        {
            current->right = new Node(rightVal);
            q.push(current->right);
        }
    }
    return root;
}

// Driver code
int main()
{
    cout << "Enter tree in level order (use -1 for NULL):" << endl;
    Node *root = buildTree();

    int result = solve(root);
    cout << "Sum of the longest path: " << result << endl;

    return 0;
}
