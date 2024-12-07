#include <bits/stdc++.h>
using namespace std;

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

class Solution
{
public:
    // Helper function to check if the tree is balanced
    pair<bool, int> isBalancedFast(Node *root)
    {
        // Base case: if the root is NULL
        if (root == NULL)
        {
            return {true, 0}; // {isBalanced, height}
        }

        // Recursive calls for left and right subtrees traversal(entire tree)
        pair<bool, int> left = isBalancedFast(root->left);
        pair<bool, int> right = isBalancedFast(root->right);

        // Check if left and right subtrees are balanced(to store if the left and right subtree is balanced or not of each node)
        bool leftBalanced = left.first;
        bool rightBalanced = right.first;

        // Check if the height difference is at most 1(used for returning true by calcu of height)
        bool heightDiff = abs(left.second - right.second) <= 1; // returns true

        // Final result: current node is balanced if both subtrees are balanced
        // and their height difference is <= 1
        bool isBalanced = leftBalanced && rightBalanced && heightDiff; // final ans returning true

        // Calculate the height of the current node
        int height = max(left.second, right.second) + 1;//height to cal karna h padhega for balance calc

        return {isBalanced, height};
    }

    // Function to check if the tree is balanced
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first; // Only the balance status is needed
    }
};

int main()
{
    // Sample tree:
    /*
            1
           / \
          2   3
         / \
        4   5
    */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution solution;
    bool treeBalanced = solution.isBalanced(root);

    cout << "Is the tree balanced? " << (treeBalanced ? "Yes" : "No") << endl;

    return 0;
}
