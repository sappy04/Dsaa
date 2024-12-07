#include <iostream>
#include <stack>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to insert a node in a BST
Node* insertBST(Node* root, int value) {
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insertBST(root->left, value);
    else
        root->right = insertBST(root->right, value);

    return root;
}

// Function to merge two BSTs with space complexity O(h1 + h2)
Node* mergeBSTs(Node* root1, Node* root2) {
    if (!root1) return root2;
    if (!root2) return root1;

    stack<Node*> s1, s2;

    // Helper function to push all left nodes into a stack
    auto pushLeft = [](Node* node, stack<Node*>& s) {
        while (node) {
            s.push(node);
            node = node->left;
        }
    };

    // Initialize stacks with leftmost nodes of both trees
    pushLeft(root1, s1);
    pushLeft(root2, s2);

    Node* mergedRoot = NULL;
    Node* current = NULL;

    // Iteratively merge both BSTs
    while (!s1.empty() || !s2.empty()) {
        Node* top1 = s1.empty() ? NULL : s1.top();
        Node* top2 = s2.empty() ? NULL : s2.top();

        Node* smaller;
        if (!top2 || (top1 && top1->data <= top2->data)) {
            smaller = top1;
            s1.pop();
            pushLeft(smaller->right, s1);
        } else {
            smaller = top2;
            s2.pop();
            pushLeft(smaller->right, s2);
        }

        // Insert the smaller node into the new BST
        Node* newNode = new Node(smaller->data);
        if (!mergedRoot) {
            mergedRoot = newNode;
            current = newNode;
        } else {
            current->right = newNode;
            current = current->right;
        }
    }

    return mergedRoot;
}

// Helper function to print the in-order traversal of a BST
void printInOrder(Node* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

// Driver code
int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;

    // Construct first BST
    root1 = insertBST(root1, 3);
    root1 = insertBST(root1, 1);
    root1 = insertBST(root1, 5);

    // Construct second BST
    root2 = insertBST(root2, 4);
    root2 = insertBST(root2, 2);
    root2 = insertBST(root2, 6);

    // Merge the BSTs
    Node* mergedRoot = mergeBSTs(root1, root2);

    // Print in-order traversal of the merged BST
    cout << "In-order traversal of merged BST: ";
    printInOrder(mergedRoot);
    cout << endl;

    return 0;
}




//  THROUGH LINKLIST
// #include <bits/stdc++.h>
// using namespace std;

// // Node structure
// struct Node {
//     int data;
//     Node* left;
//     Node* right;

//     Node(int val) {
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };

// // Helper function to insert a node in a BST
// Node* insertBST(Node* root, int value) {
//     if (root == NULL)
//         return new Node(value);

//     if (value < root->data)
//         root->left = insertBST(root->left, value);
//     else
//         root->right = insertBST(root->right, value);

//     return root;
// }

// // Function to convert a BST into a sorted doubly linked list
// void Convertintosorteddll(Node* root, Node*& head) {
//     if (root == NULL) {
//         return;
//     }

//     // Recursive call for the right subtree first
//     Convertintosorteddll(root->right, head);

//     // Processing the current node
//     root->right = head; // Link the current node's right to the head
//     if (head != NULL) { // If the head exists, link its left pointer back to the current node
//         head->left = root;
//     }

//     // Update the head to the current node
//     head = root;

//     // Recursive call for the left subtree
//     Convertintosorteddll(root->left, head);
// }

// // Helper function to get the head of the DLL (ensures the DLL starts from the smallest node)
// Node* bstToSortedDLL(Node* root) {
//     Node* head = NULL; // Initialize the head of the DLL
//     Convertintosorteddll(root, head); // Perform the conversion
//     return head; // Return the head of the DLL
// }

// // Function to print the sorted doubly linked list
// void printDLL(Node* head) {
//     Node* current = head;
//     cout << "Doubly Linked List: ";
//     while (current != NULL) {
//         cout << current->data << " ";
//         current = current->right; // Move to the next node in the DLL
//     }
//     cout << endl;
// }

// // Driver Code
// int main() {
//     Node* root = NULL;

//     // Construct the BST
//     root = insertBST(root, 10);
//     root = insertBST(root, 5);
//     root = insertBST(root, 15);
//     root = insertBST(root, 2);
//     root = insertBST(root, 7);

//     // Convert BST to sorted DLL
//     Node* head = bstToSortedDLL(root);

//     // Print the DLL
//     printDLL(head);

//     return 0;
// }
