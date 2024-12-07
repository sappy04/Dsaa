#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Node structure for the binary tree
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Recursive function to find the number of paths with a given sum `k`
void solve(Node *root, int k, int &count, vector<int> path)
{
    if (root == NULL)
    {
        return;
    } // agar tree khali nahi hai to.

    path.push_back(root->data); // pehla node daala tree ka
    solve(root->left, k, count, path);
    solve(root->right, k, count, path); // right me traverse kiya for storing the path

    // check for k sum
    int size = path.size(); // path ka size store kar liya
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {                   // path k ekdam neeche se start kiya
        sum += path[i]; // ek path ka ek ek karke bottom se plus hote jaa raha hai
        if (sum == k)
        {
            count++; // k sum mil gaya to count badh gaya
        }
    }
    path.pop_back(); // har ek level pe paths different hai so jaise jaise hum upar badhenge path k humme peeche se ek ek karke values pop karne padhenge
}

// Function to calculate the number of paths that sum up to `k`
int summ(Node *root, int k)
{                     // path ko store karenge aur uske adar k sare element ko combination ko sum karke dekhenege agar k k equal agaya to count badha denge
    vector<int> path; // path store karne k liye (pura root to leaf)
    int count = 0;    // count for kitne aise k sum possible hai ek path mai
    solve(root, k, count, path);
    return count;
}

// Helper function to build the binary tree
Node *buildTree()
{
    int val;
    cin >> val;
    if (val == -1)
        return nullptr; // Use -1 to denote NULL nodes

    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal; // Input left child
        if (leftVal != -1)
        {
            current->left = new Node(leftVal);
            q.push(current->left);
        }

        cin >> rightVal; // Input right child
        if (rightVal != -1)
        {
            current->right = new Node(rightVal);
            q.push(current->right);
        }
    }
    return root;
}

// Driver code
int main()
{
    cout << "Enter tree in level order (use -1 for NULL):" << endl;
    Node *root = buildTree();

    int k;
    cout << "Enter the sum to check: ";
    cin >> k;

    int result = summ(root, k);
    cout << "Number of paths with sum " << k << ": " << result << endl;

    return 0;
}
