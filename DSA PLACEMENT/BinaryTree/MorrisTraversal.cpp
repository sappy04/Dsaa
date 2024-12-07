#include <iostream>
using namespace std;

// Definition of Node for the binary tree
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Morris In-order Traversal
// void morrisInOrder(Node* root) {
//     Node* current = root;

//     while (current != NULL) {
//         // If there is no left child, print the current node and move to the right
//         if (current->left == NULL) {
//             cout << current->data << " ";
//             current = current->right;
//         } else {
//             // Find the inorder predecessor of the current node
//             Node* predecessor = current->left;
//             while (predecessor->right != NULL && predecessor->right != current) {
//                 predecessor = predecessor->right;
//             }

//             // If the right pointer of the predecessor is NULL, set it to the current node
//             if (predecessor->right == NULL) {
//                 predecessor->right = current;
//                 current = current->left;
//             } else {
//                 // Restore the tree by setting the right pointer of the predecessor back to NULL
//                 cout << current->data << " ";
//                 predecessor->right = NULL;
//                 current = current->right;
//             }
//         }
//     }
// }

// Morris preorder=FLATTERN A BT TO LINKLIST.
void morrisPreOrder(Node *root)
{
    Node *current = root;

    while (current != NULL)
    {
        // If no left child, print current node and move right
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            // Find the inorder predecessor
            Node *predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current)
            {
                predecessor = predecessor->right;
            }

            // Create thread and print before going to left child
            if (predecessor->right == NULL)
            {
                cout << current->data << " "; // Pre-order: Process before left
                predecessor->right = current;
                current = current->left;
            }
            else
            {
                // Restore tree structure after visiting left subtree
                predecessor->right = NULL;
                current = current->right;
            }
        }
    }
}

// Helper function to create a binary tree
Node *buildTree()
{
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->right = new Node(6);
    // root->left->left->right = new Node(7);
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    return root;
}

// Main function
int main()
{
    Node *root = buildTree();
    cout << "In-order traversal using Morris Traversal: ";
    morrisPreOrder(root);
    return 0;
}
