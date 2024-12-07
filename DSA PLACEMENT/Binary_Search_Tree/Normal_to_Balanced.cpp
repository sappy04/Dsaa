#include <iostream>
#include <vector>
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

// ascending order mai tree ko return karta hai (rule)
void inordered(Node* root, vector<int>& inorderval) {
    if (root == NULL)
        return;

    inordered(root->left, inorderval);
    inorderval.push_back(root->data);
    inordered(root->right, inorderval);
}

Node* inordertoBST(int s, int e, vector<int>& inorderval) {
    if (s > e) // start agar end se bara hogaya then to koi fayda nahi
        return NULL;

    int mid = s + (e - s) / 2; // mid value nikala
    Node* root = new Node(inorderval[mid]); // root node ko mid value se banaya
    root->left = inordertoBST(s, mid - 1, inorderval); // left subtree (s se mid-1 tak)
    root->right = inordertoBST(mid + 1, e, inorderval); // right subtree (mid+1 se e tak)
    return root; // root return karta hai
}

Node* balancedBST(Node* root) {
    vector<int> inorderval;
    // store inorder values in sorted order
    inordered(root, inorderval); // values laya ascending mai phir pass kar diya value 
    return inordertoBST(0, inorderval.size() - 1, inorderval); // ascending order mai se hi maine tree bana dia
}

// Helper function to print the tree in-order (for verification)
void printInOrder(Node* root) {
    if (root == NULL)
        return;

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

// Driver code
int main() {
    // Example tree
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(15);
    root->left->left = new Node(7);
    root->left->right = new Node(9);
    root->right->right = new Node(20);

    // Convert to balanced BST
    Node* balancedRoot = balancedBST(root);

    // Print the balanced BST
    cout << "In-order traversal of balanced BST: ";
    printInOrder(balancedRoot);
    cout << endl;

    return 0;
}
