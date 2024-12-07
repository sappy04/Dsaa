#include <bits/stdc++.h>
using namespace std;

// Definition of the TreeNode structure
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to perform in-order traversal and collect values in a vector
void inorderTraversal(TreeNode *root, vector<int> &inorder)
{
    if (!root)
        return;

    inorderTraversal(root->left, inorder);  // Traverse left subtree
    inorder.push_back(root->val);           // Store the current node's value
    inorderTraversal(root->right, inorder); // Traverse right subtree
}

// Function to populate the tree using pre-order traversal and sorted values
void populateTree(TreeNode *root, vector<int> &sortedValues, int &index)
{
    if (!root)
        return;

    root->val = sortedValues[index++];              // Assign the current value from sorted list
    populateTree(root->left, sortedValues, index);  // Populate left subtree
    populateTree(root->right, sortedValues, index); // Populate right subtree
}

// Main function to transform the tree
void transformTree(TreeNode *root)
{
    vector<int> inorder;             // To store in-order traversal
    inorderTraversal(root, inorder); // Step 1: Find in-order traversal of the CBT

    sort(inorder.begin(), inorder.end()); // Step 2: Sort the in-order traversal

    int index = 0;
    populateTree(root, inorder, index); // Step 3: Populate the tree using pre-order traversal
}

// Function to print the tree in level-order for verification
void levelOrderPrint(TreeNode *root)
{
    if (!root)
        return;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();

        cout << curr->val << " ";

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    cout << endl;
}

int main()
{
    // Example tree:
    //         3
    //        / \
    //       1   5
    //      / \
    //     0   2

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);

    cout << "Original tree (level-order): ";
    levelOrderPrint(root);

    transformTree(root);

    cout << "Transformed tree (level-order): ";
    levelOrderPrint(root);

    return 0;
}
