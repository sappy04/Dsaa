#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    // Map to store the topmost node for each horizontal distance (HD)
    map<int, int> topNode;

    // Queue to perform level-order traversal
    // Pair contains the node and its corresponding horizontal distance
    queue<pair<Node *, int>> q;

    // Start with the root node at horizontal distance 0
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        // If a node at this horizontal distance is not already present in the map, add it
        if (topNode.find(hd) == topNode.end())//checking mere hd k respect mai pehle se hi koi mapping exist karta hai kya?...findkhojta hai mapping exist karta hai ki nahi
        {
            topNode[hd] = frontNode->data;//agar nahi hai to hd ke respect mai value store kar denge
        }

        // Push the left child with horizontal distance - 1
        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        // Push the right child with horizontal distance + 1
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    // Traverse the map to prepare the top view
    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }

    return ans;
}

vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, int> bottomNode;
    queue<pair<Node *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        // Replace the value for every HD with the current node
        bottomNode[hd] = frontNode->data;

        if (frontNode->left)
            q.push({frontNode->left, hd - 1});
        if (frontNode->right)
            q.push({frontNode->right, hd + 1});
    }

    for (auto i : bottomNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

// Left View
vector<int> leftView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size(); // Number of nodes at the current level

        for (int i = 0; i < n; i++)
        {
            Node *frontNode = q.front();
            q.pop();

            // Add the first node of each level to the answer
            if (i == 0)
            {
                ans.push_back(frontNode->data);
            }

            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }
    }

    return ans;
}

// Right View
vector<int> rightView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size(); // Number of nodes at the current level

        for (int i = 0; i < n; i++)
        {
            Node *frontNode = q.front();
            q.pop();

            // Add the last node of each level to the answer
            if (i == n - 1)
            {
                ans.push_back(frontNode->data);
            }

            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }
    }

    return ans;
}

// Utility function to create a binary tree for testing
Node *buildTree()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

int main()
{
    Node *root = buildTree();

    vector<int> top = topView(root);
    cout << "Top View: ";
    for (int val : top)
        cout << val << " ";
    cout << endl;

    vector<int> bottom = bottomView(root);
    cout << "Bottom View: ";
    for (int val : bottom)
        cout << val << " ";
    cout << endl;

    vector<int> left = leftView(root);
    cout << "Left View: ";
    for (int val : left)
        cout << val << " ";
    cout << endl;

    vector<int> right = rightView(root);
    cout << "Right View: ";
    for (int val : right)
        cout << val << " ";
    cout << endl;

    return 0;
}
