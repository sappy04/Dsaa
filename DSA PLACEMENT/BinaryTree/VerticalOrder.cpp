#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// Definition of a Tree Node
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

// Function for Vertical Order Traversal
vector<int> verticalOrder(Node *root)
{
    vector<int> ans;
    if (root == NULL) // tree khali hai to
        return ans;

    map<int, map<int, vector<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> q;
    q.push(make_pair(root, make_pair(0, 0))); // root(with hd and level) node ko pakar liya

    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front(); // queue ka pehla vlaue nikal le(ye map mai ghusaya just)
        q.pop();
        Node *frontNode = temp.first; // nikal liya pehla node(with value)
        int hd = temp.second.first;   // line 30 ka args ka second ka first hi hai na?to usse hi mark kar diya
        int lvl = temp.second.second; // same for level

        nodes[hd][lvl].push_back(frontNode->data); // per no.line k sath mapping create kar rha hoon
//0 center point hai
        if (frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1))); //  line k left mai jane se level to bad hi raha hai(going->vetically towaards left) and horizonatal distance bhi decrement hota hai
        if (frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1))); // horizonatal distance bhi increment hota hai
    }

    for (auto i : nodes)//printing chalu kiya map se
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
                ans.push_back(k);
        }
    }

    return ans;
}

// Helper Function to Build the Tree (For testing)
Node *buildSampleTree()
{
    Node *root = new Node(1);
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
int main()
{
    Node *root = buildSampleTree();           // Build the tree
    vector<int> result = verticalOrder(root); // Get the vertical order traversal

    // Output the result without spaces between numbers
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i]; // Print each value from the result vector
    }
    cout << endl;

    return 0;
}
