#include <bits/stdc++.h>
using namespace std;

// Definition for the Node structure
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

class Solution
{
public:
    int height(struct Node *node)
    {
        if (node == NULL) // ye call pura root se leaf node tak jayega..
        {
            return 0; // jab leaf node mai pohuch jayega tab just upar wale node ko zero return karega
        }
        int left = height(node->left);   // pehla node null nahi hone k baad left gaya phir wapis check kiya ki ye kya null hai? tab tak neeche jata raha jab tak null nahi hua.. null milte hi ise node ko zero return kiya
        int right = height(node->right); // zero return karne se call usi node se right pe chala gya.. phir se left check kiya kya node null hai kya? agar haa to zero return kiya aur right mai check kiya ussi node ka
        int ans = max(left, right) + 1;  // donno left right ka max value +1 karke ans upar wale node ko pass on karta hai
        return ans;
    }
};

int main()
{
    // Creating a sample binary tree
    /*
          1
         / \
        2   3
       / \
      4   5
    */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Using the Solution class to find the height of the binary tree
    Solution solution;
    int treeHeight = solution.height(root);

    cout << "Height of the binary tree: " << treeHeight << endl;

    return 0;
}
