#include <iostream>
#include <queue>
#include <map>
#include <set>
using namespace std;

// Definition of Node for the binary tree
struct Node
{
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Step 1: Map each node to its parent and find the target node
Node *createParentMapping(Node *root, map<Node *, Node *> &nodeToParent, int target, Node *&targetNode)
{
    queue<Node *> q;
    q.push(root);              // ye root, tree ka main root hai
    nodeToParent[root] = NULL; // Root ka koi parent nahi hai

    while (!q.empty()) // ye kiya maine level order traversal
    {
        Node *current = q.front();//tree k root ko le liya current mai
        q.pop();

        if (current->data == target)//yaha pe mai bas target node khoj raha hoon neeche mapping ho raha hai issi function mai
        {
            targetNode = current; // Target node found
        }
        //mapping chalu ho gaya
        if (current->left)
        {
            nodeToParent[current->left] = current; // root k left child ko map kar diya ki bhai jaha se aya hai wo tera parent hai
            q.push(current->left);                 // queue mai fir daaal diya
        }

        if (current->right)
        {
            nodeToParent[current->right] = current; // root k right child ko map kar diya ki bhai jaha se aya hai wo tera parent hai
            q.push(current->right);                 // queue mai fir daal diya
        }
    }
    return targetNode;
}

// Step 2: Perform BFS to burn the tree
int burnTree(Node *targetNode, map<Node *, Node *> &nodeToParent)
{
    queue<Node *> q;//last queue hai jiske uoar timing depend karta hai
    set<Node *> visited;//ismai visited hai nahi stored hai

    q.push(targetNode);// last queue mai target node daal diya
    visited.insert(targetNode);//visited mai bhi target node daal diya
    int time = 0;//time ko initialise kar diya zero se

    while (!q.empty())
    {
        int size = q.size();//ye help karta hai ki current node k saree bache aur parent ko include karke kitne hai
        bool fireSpread = false;

        for (int i = 0; i < size; i++)//process kar raha neighbouring nodes ko
        {
            Node *current = q.front();
            q.pop();

            // Visit the left child
            if (current->left && !visited.count(current->left))//check karlo current ka left visited to nahi hai(visited.count(current->left)->baat karta hai sirf 0/1 mai)) na aur and null to nahi hai na(current->left)?
            {
                fireSpread = true;//addition hua hai queue mai, tab flag ko true mar kardo for time calculation
                visited.insert(current->left);//visited mark kar do
                q.push(current->left);//queue mai daal do
            }

            
            if (current->right && !visited.count(current->right) )//same for right
            {
                fireSpread = true;
                visited.insert(current->right);
                q.push(current->right);
            }

            // Visit the parent
            if (nodeToParent[current] && !visited.count(nodeToParent[current]))//same for current node ka parent k liye
            {
                fireSpread = true;
                visited.insert(nodeToParent[current]);
                q.push(nodeToParent[current]);
            }
        }

        if (fireSpread)//flag true hai to time badhao
        {
            time++;
        }
    }

    return time;
}

// Main function to calculate the minimum time to burn the tree
int minTime(Node *root, int target)
{
    // Step 1: Create a mapping of nodes to their parents
    map<Node *, Node *> nodeToParent;//mapping create karne k liye structure
    Node *targetNode = NULL; // target node kaha milla khojne k liye,passed on ho jayega function mai
    createParentMapping(root, nodeToParent, target, targetNode);

    return burnTree(targetNode, nodeToParent); // tree ko burn karne k liye target node aur mapping chahiye na to wohi pass kiya
}

// Helper function to create a binary tree for testing
Node *buildTree()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    return root;
}

// Main function
int main()
{
    Node *root = buildTree();
    int target = 8;

    cout << "Minimum time to burn the tree: " << minTime(root, target) << endl;
    return 0;
}
