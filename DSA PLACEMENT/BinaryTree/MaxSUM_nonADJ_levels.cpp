#include <iostream>
#include <unordered_map>
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

// Helper function to calculate the max sum of non-adjacent nodes
pair<int, int> solve(Node *root)
{
    if (root == NULL)
    {
        return {0, 0}; // {include, exclude}
    }

    // Recursively calculate for left and right subtrees
    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    // If we include the current node
    int include = root->data + left.second + right.second; // included mai root ka value + pair ka second hamesha as wo non adj level ka hi value hai

    // If we exclude the current node
    int exclude = max(left.first, left.second) + max(right.first, right.second); // current node exclude karne se left pair k max +right pair ka max ka sum return kar do

    // Return both values
    return {include, exclude}; // yaha se dono value mai bhej diya function mai getmax jaha se mai max value le liya
}

// Function to find the maximum sum of non-adjacent nodes
int getMaxSum(Node *root)
{
    pair<int, int> result = solve(root);     // pehla int hai root ko consider karke maxsum retrun karne wala at currernt level aur dusra wala hai bina root ko consider karke
    return max(result.first, result.second); // max from current level or exculding current level
}

// Helper function to build a tree
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

    cout << "Maximum sum of non-adjacent nodes: " << getMaxSum(root) << endl;

    return 0;
}
