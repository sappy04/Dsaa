#include <iostream>
using namespace std;

// Definition of Node for the binary tree
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

// Function to find the index of the current root in inorder traversal
int findpos(int inorder[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (inorder[i] == element)
        {
            return i; // index of root in inorder
        }
    }
    return -1; // not found (edge case)
}

// Recursive function to construct the tree
Node *solve(int inorder[], int preorder[], int &pre_index, int in_start, int in_end, int n)//pre order se print kar rahe hai na isliye left se pehle traverse karenge
{
    if (pre_index > n || in_start > in_end)//agar mere pointers bahar jaa rahe array size k null return karo
    {
        return NULL;
    }

    int element = preorder[pre_index++];         // preorder ka pehla element nikal liya aur pre order k next element pe set kar diya
    Node *root = new Node(element);              // tree ka root bana diya preorder k pehle value se
    int position = findpos(inorder, element, n); // inorder mai mera root kaha hai uska index dega

    // Construct left subtree
    root->left = solve(inorder, preorder, pre_index, in_start, position - 1, n);//segregation kiya left subtree ka(ismai inorder,postorder arrays hai with left ka range and pre order ka starting index and inorder ka length)
    // Construct right subtree
    root->right = solve(inorder, preorder, pre_index, position + 1, in_end, n);//segregration kiya right subtree ka

    return root;//tree hi return kar diya
}

// Function to build the tree
Node *buildTree(int inorder[], int preorder[], int n)//n is the size of the tree(no.of nodes should be same)
{
    int pre_index = 0; // Initialize preorder index
    return solve(inorder, preorder, pre_index, 0, n - 1, n);
}

// Helper function to print postorder traversal
void printPostorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

// Main function for testing
int main()
{
    // Input arrays
    int inorder[] = {3, 1, 4, 0, 5, 2};
    int preorder[] = {0, 1, 3, 4, 2, 5};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    // Build the tree
    Node *root = buildTree(inorder, preorder, n);

    // Print the postorder traversal of the constructed tree
    cout << "Postorder traversal of the constructed tree: ";
    printPostorder(root);
    cout << endl;

    return 0;
}

// using postorder and inorder bulding a tree and giving its inorder
// #include <iostream>
// using namespace std;

// // Definition of Node for the binary tree
// struct Node
// {
//     int data;
//     Node *left;
//     Node *right;

//     Node(int val)
//     {
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };

// // Function to find the index of the current root in inorder traversal
// int findpos(int inorder[], int element, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (inorder[i] == element)
//         {
//             return i; // index of root in inorder
//         }
//     }
//     return -1; // not found (edge case)
// }

// // Recursive function to construct the tree
// Node *solve(int inorder[], int postorder[], int &post_index, int in_start, int in_end, int n)//post order se print kar rahe hai na isliye right se pehle traverse karenge
// {
//     if (post_index < 0 || in_start > in_end)
//     { // If index is out of bounds, return NULL
//         return NULL;
//     }

//     int element = postorder[post_index--];       // Root is the last element of postorder; decrement index
//     Node *root = new Node(element);              // Create a new node for the root
//     int position = findpos(inorder, element, n); // Find root in inorder array

//     // Construct right subtree first (postorder processes right subtree before left subtree)
//     root->right = solve(inorder, postorder, post_index, position + 1, in_end, n); // right pehla call kiya hai IMPORTANT hai
//     // Construct left subtree
//     root->left = solve(inorder, postorder, post_index, in_start, position - 1, n);

//     return root;
// }

// // Function to build the tree
// Node *buildTree(int inorder[], int postorder[], int n)
// {
//     int post_index = n - 1; // Initialize postorder index to the last element
//     return solve(inorder, postorder, post_index, 0, n - 1, n);
// }

// // Helper function to print preorder traversal (for verification)
// void printPreorder(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     cout << root->data << " ";
//     printPreorder(root->left);
//     printPreorder(root->right);
// }

// // Main function for testing
// int main()
// {
//     // Input arrays
//     int inorder[] = {4, 8, 2, 5, 1, 6, 3, 7};
//     int postorder[] = {8, 4, 5, 2, 6, 7, 3, 1};
//     int n = sizeof(inorder) / sizeof(inorder[0]);

//     // Build the tree
//     Node *root = buildTree(inorder, postorder, n);

//     // Print the preorder traversal of the constructed tree
//     cout << "Preorder traversal of the constructed tree: ";
//     printPreorder(root);
//     cout << endl;

//     return 0;
// }
