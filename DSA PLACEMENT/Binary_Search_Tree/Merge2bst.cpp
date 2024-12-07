#include <iostream>
#include <vector>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// yaha pe ek ek karke bst ayega aur sorted hoke nikal jayega
void inordered(Node *root, vector<int> &inorderval)
{
    if (root == NULL)
        return;

    inordered(root->left, inorderval);
    inorderval.push_back(root->data);
    inordered(root->right, inorderval);
}

// yaha pe ek hi array ayega pura sorted jisko humme bst mai sort karnaa padhega
Node *inordertoBST(int s, int e, vector<int> &inorderval)
{
    if (s > e) // start agar end se bara hogaya then to koi fayda nahi
        return NULL;

    int mid = s + (e - s) / 2;                          // mid value nikala
    Node *root = new Node(inorderval[mid]);             // root node ko mid value se banaya
    root->left = inordertoBST(s, mid - 1, inorderval);  // left subtree (s se mid-1 tak)
    root->right = inordertoBST(mid + 1, e, inorderval); // right subtree (mid+1 se e tak)
    return root;                                        // root return karta hai
}

// yaha pe dono sorted bst in form of arrays aayenge
vector<int> mergevector(vector<int> bst1, vector<int> bst2)
{
    vector<int> ans(bst1.size() + bst2.size()); // to store the final merged sorted array
    int i = 0;                                  // double pointer game
    int j = 0;
    int k = 0; // ans ko bharne k liye
    while (i < bst1.size() && j < bst2.size())
    {
        if (bst1[i] < bst2[j]) // mere donno arrays ka first element jo bhi chota hoga ghus jayega
        {
            ans[k++] = bst1[i];
            i++;
        }
        else
        {
            ans[k++] = bst2[j];
            j++;
        }
    }
    while (i < bst1.size()) // checking if my total array is completed
    {
        ans[k++] = bst1[i];
        i++;
    }
    while (j < bst2.size()) // checking if my total array is completed
    {
        ans[k++] = bst2[j];
        j++;
    }
    return ans;
}

Node *mergeBST(Node *root1, Node *root2)
{
    // store inorders
    vector<int> bst1, bst2;
    inordered(root1, bst1); // got the bst in sorted vector by inorder traversal
    inordered(root2, bst2);
    vector<int> mergedvectors = mergevector(bst1, bst2); // merged vector agaya
    int start = 0, end = mergedvectors.size() - 1;
    return inordertoBST(start, end, mergedvectors); // usko bst mai convert kar diya
}

// Helper function to print the in-order traversal of a BST
void printInOrder(Node *root)
{
    if (root == NULL)
        return;

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

// Helper function to insert nodes into a BST
Node *insertBST(Node *root, int value)
{
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insertBST(root->left, value);
    else
        root->right = insertBST(root->right, value);

    return root;
}

// Driver code
int main()
{
    Node *root1 = NULL, *root2 = NULL;

    // Construct the first BST
    root1 = insertBST(root1, 3);
    root1 = insertBST(root1, 1);
    root1 = insertBST(root1, 5);

    // Construct the second BST
    root2 = insertBST(root2, 4);
    root2 = insertBST(root2, 2);
    root2 = insertBST(root2, 6);

    // Merge the BSTs
    Node *mergedRoot = mergeBST(root1, root2);

    // Print the merged BST in in-order
    cout << "In-order traversal of merged BST: ";
    printInOrder(mergedRoot);
    cout << endl;

    return 0;
}

// Node* Convertintosorteddll(Node *root,Node *&head)
// {
//     if (root == NULL)
//     {
//         return NULL;
//     }
//     Convertintosorteddll(root->left, head);//left right traversal
//     root->right = head;//tree k root k first left child ko head mark diya
//     if (head != NULL)
//     {
//         head->left = root;
//     }
//     head = root;//alloted head ko root maark kardo
//     Convertintosorteddll(root->right, head);
// }