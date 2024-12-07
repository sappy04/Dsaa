#include <iostream>
#include <queue>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to find the lowest common ancestor
Node* lca(Node* root, int n1, int n2) {
    // base case
    if (root == NULL) {
        return NULL;
    }
    if (root->data == n1 || root->data == n2) { // agar root hi n1/n2 hua to, root hi lca hai
        return root; // root hi answer hai
    }

    // agar abhi tak lca nahi milla to left aur right traversal karo
    Node* left = lca(root->left, n1, n2); // left mai khojte jao per node kya tu n1/n2 hai?
    Node* right = lca(root->right, n1, n2); // right mai khojte jao per node kya tu n1/n2 hai?

    if (left != NULL && right != NULL) { // left aur right k common root ko return kardo
        return root; // root hi lca hai
    } else if (left != NULL) { // left k subtree hi lca hai
        return left; // left k root hi lca hai
    } else if (right != NULL) {
        return right; // right k root hi lca hai
    } else {
        return NULL; // agar donno hi null hai then answer to null hoga hi bhai
    }
}

// Helper function to build the binary tree
Node* buildTree() {
    int val;
    cin >> val;
    if (val == -1) return nullptr; // Use -1 to denote NULL nodes

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal; // Input left child
        if (leftVal != -1) {
            current->left = new Node(leftVal);
            q.push(current->left);
        }

        cin >> rightVal; // Input right child
        if (rightVal != -1) {
            current->right = new Node(rightVal);
            q.push(current->right);
        }
    }
    return root;
}

// Driver code to test the function
int main() {
    cout << "Enter tree in level order (use -1 for NULL):" << endl;
    Node* root = buildTree();

    int n1, n2;
    cout << "Enter two nodes to find their LCA: ";
    cin >> n1 >> n2;

    Node* result = lca(root, n1, n2);
    if (result) {
        cout << "LCA of " << n1 << " and " << n2 << " is: " << result->data << endl;
    } else {
        cout << "LCA not found!" << endl;
    }

    return 0;
}
//3 5 1 6 2 0 8 -1 -1 7 4 -1 -1 -1 -1 -1 -1 -1 -1
//5 1
