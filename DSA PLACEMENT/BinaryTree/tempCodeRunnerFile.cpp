#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// Definition of a Tree Node
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

// Function for Vertical Order Traversal
vector<int> verticalOrder(Node* root) {
    vector<int> result; 
    if (root == NULL) // If tree is empty
        return result;

    // Map to store nodes in vertical order: 
    // First map for horizontal distance (HD), 
    // second map for nodes at that HD
    map<int, vector<int>> nodes;

    // Queue to store nodes along with their HD
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0)); // root with HD 0

    while (!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();
        
        Node* frontNode = temp.first;
        int hd = temp.second; // horizontal distance

        // Store nodes at the same HD (no need to keep level)
        nodes[hd].push_back(frontNode->data);

        // Push left and right children with updated HD
        if (frontNode->left) 
            q.push(make_pair(frontNode->left, hd - 1));
        if (frontNode->right) 
            q.push(make_pair(frontNode->right, hd + 1));
    }

    // Traverse the map and collect the results in vertical order
    for (auto& entry : nodes) {
        for (int val : entry.second) {
            result.push_back(val);
        }
    }

    return result;
}

// Helper Function to Build the Tree (For testing)
Node* buildSampleTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(8);
    root->right->right->left->left = new Node(9);
    return root;
}

// Main Function
int main() {
    Node* root = buildSampleTree(); // Build the tree
    vector<int> result = verticalOrder(root); // Get the vertical order traversal

    // Output the result without spaces between numbers
    for (int val : result) {
        cout << val;
    }
    cout << endl;

    return 0;
}
