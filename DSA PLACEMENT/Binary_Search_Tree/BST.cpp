#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};
void levelorder(Node *root) // builded tree ata hai yaha aur uska sirf processing hota hai....level order traversal
{
    if (root == NULL) // matlab tree khali hai
    {
        return;
    }

    queue<Node *> q; // Create a queue to store nodes
    q.push(root);    // q mai jaise hi root print hota hai uske sang sang hi uske child ko add kar diya jata hai

    while (!q.empty())
    {
        int levelSize = q.size(); // Number of nodes at the current level

        for (int i = 0; i < levelSize; i++)
        {
            Node *temp = q.front(); // levelwise element nikala,temp koi queue nahi hai balki single element hai for processing
            q.pop();

            cout << temp->data << " "; // aur print kar diya simple

            // agar current node ka koi sa bhi child (left/right) null hua to kuch push nahi hoga
            if (temp->left) // abhi agar issi root node ka left child hai to queue mai daal do
            {
                q.push(temp->left); // left ghus gya que mai
            }

            if (temp->right) // abhi agar issi root node ka right child hai to queue mai daal do
            {
                q.push(temp->right); // uska right bhi ghus gaya queue mai
            }
        }
        cout << endl; // Move to the next line after printing all nodes at the current level
    }
}

Node *minval(Node* root)
{
    Node*temp=root;
    while(temp && temp->left!=NULL)//min value left most mai hai na?to left most kaise samjh ayega?--jab left->left  null ho jaye
    {
        temp=temp->left;
    }
    return temp;
}
Node *maxval(Node* root)
{
    Node*temp=root;
    while(temp && temp->right!=NULL)//min value left most mai hai na?to left most kaise samjh ayega?--jab left->left  null ho jaye
    {
        temp=temp->right;
    }
    return temp;
}
Node *deleted(Node *root,int val)
{
    //base case
    if(root==NULL)
    {
        return root;
    }
    if(root->data==val)//root ko hi delete karna hai
    {
        //0child
        if(root->left==NULL && root->right==NULL)//koi child hi nahi hai mc
        {
            delete root;
            return NULL;
        }
        //1child->left child hai ya to right child hai
        if(root->left!=NULL && root->right==NULL)
        {
            Node *temp=root->left;//connection bachaya parent to child ka
            delete root;//parent ko delete kiya
            return temp;//parent k parent k saathconnection jor lo
        }
        if(root->left==NULL && root->right!=NULL)
        {
            Node *temp=root->right;//connection bachaya parent to child ka
            delete root;//parent ko delete kiya
            return temp;//parent k parent k saathconnection jor lo
        }

        //2child
        if(root->left!=NULL && root->right!=NULL)
        {
            int minvalue=minval(root->right)->data;//ye nikal gya right subtree ka min value
            root->data=minvalue;//deleted item ko override kar diya
            root->right=deleted(root->right,minvalue);//right subtree se min value ko delete kara
        }

    }
    else if(root->data>val)//root bara hai value se then left mai khoj
    {
        root->left=deleted(root->left,val);
    }
    else
    {
        root->right=deleted(root->right,val);
    }
    return root;

}
bool searchInBST(Node *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    if (root->data < x) // agar root se badha value hai to
    {
        return searchInBST(root->right, x);//right maai search karo
    }
    else
    {
        return searchInBST(root->left, x); // left maai search karo
    }
}
Node *Insertion(Node *&root, int d) // o(logn)
{
    // base case
    if (root == NULL) // agar tree hi khali hua to
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data) // greater values ssab right mai jayega

    {
        root->right = Insertion(root->right, d);
    }
    if (d < root->data) // kam values left part mai gaya
    {
        root->left = Insertion(root->left, d);
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        Insertion(root, data);
        cin >> data;
    }
}
int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST" << endl;
    takeInput(root);
    levelorder(root);
    cout << "Enter value to search in BST: ";
    int searchValue;
    cin >> searchValue;
    if (searchInBST(root, searchValue))
    {
        cout << "Value " << searchValue << " found in BST." << endl;
    }
    else
    {
        cout << "Value " << searchValue << " not found in BST." << endl;
    }
    cout<<"min value is: "<<minval(root)->data<<endl;
    cout<<"max value is: "<<maxval(root)->data<<endl;
    
     cout << "Enter value to delete: ";
    int deleteValue;
    cin >> deleteValue;
    root = deleted(root, deleteValue);
    cout << "BST after deletion:" << endl;
    levelorder(root);
    
    return 0;
}




























// void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
// {
//     if (!root) // Agar root null hai to return
//         return;

//     if (root->data == key) // Agar current node ka data key ke barabar hai
//     {
//         // Inorder predecessor
//         if (root->left != NULL)
//         {
//             Node *temp = root->left;
//             while (temp->right)
//                 temp = temp->right;
//             pre = temp;
//         }

//         // Inorder successor
//         if (root->right != NULL)
//         {
//             Node *temp = root->right;
//             while (temp->left)
//                 temp = temp->left;
//             suc = temp;
//         }
//         return;
//     }

//     if (root->data > key) // Agar current node ka data key se bada hai
//     {
//         suc = root;//right mai ghus
//         findPreSuc(root->left, pre, suc, key);
//     }
//     else // Agar current ka data key se chhota hai to
//     {
//         pre = root;//left mai ghusso
//         findPreSuc(root->right, pre, suc, key);
//     }
// }

