#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void inordered(Node *root, vector<int> &inorder) // ascending order mai tree ko return karta hai(rule)
{
    if (root == NULL)
        return;

    inordered(root->left, inorder);
    inorder.push_back(root->data);
    inordered(root->right, inorder);
}

bool twosum(Node *root, int target)
{
    vector<int> inorder;
    inordered(root, inorder);
    int i = 0, j = inorder.size() - 1;
    while (i < j)
    {
        int sum = inorder[i] + inorder[j];
        if (sum == target)
        {
            return true;
        }
        else if (sum > target) // thora badha values kamane se shayad mil jaye
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}

// Helper function to insert a new node in the BST
Node *insert(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Main function for testing
int main()
{
    Node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 9);

    int target = 10;
    if (twosum(root, target))
    {
        cout << "Yes, there are two numbers in the BST whose sum is " << target << "." << endl;
    }
    else
    {
        cout << "No, there are no two numbers in the BST whose sum is " << target << "." << endl;
    }

    return 0;
}
