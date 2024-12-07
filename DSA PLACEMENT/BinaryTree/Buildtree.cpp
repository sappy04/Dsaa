#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;  // Initialize left as NULL
        this->right = NULL; // Initialize right as NULL
    }
};

Node *buildtree()
{
    cout << "Enter the data: ";
    int data;
    cin >> data;

    // Base case: if data is -1, return NULL
    if (data == -1)
    {
        return NULL;
    }

    // Create the root node
    Node *root = new Node(data);

    // Recursive calls to build the left and right subtrees
    cout << "Enter data for the left child of " << data << ": ";
    root->left = buildtree();

    cout << "Enter data for the right child of " << data << ": ";
    root->right = buildtree();

    return root;
}
void levelorder(Node *root) // builded tree ata hai yaha aur uska sirf processing hota hai
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
void buildfromlevelorder(Node *&root) // levelorder matlab queue
{
    queue<Node *> q;
    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    if (data == -1) // If root is NULL
    {
        root = NULL;
        return;
    }
    root = new Node(data); // root node banaya
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front(); // store kiya
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left); // leftnode insert kar diya root Node ka
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right); // right node insert kar diya
        }
    }
}
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " "; // node
    preorder(root->left);      // left
    preorder(root->right);     // right
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);       // left
    cout << root->data << " "; // node
    inorder(root->right);      // right
}
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);     // left
    postorder(root->right);    // right
    cout << root->data << " "; // node
}
int main()
{
    Node *root = NULL;
    int choice;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Build Tree (Recursive Input)\n";
        cout << "2. Build Tree (Level Order Input)\n";
        cout << "3. Level Order Traversal\n";
        cout << "4. Preorder Traversal\n";
        cout << "5. Inorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Building tree using recursive input...\n";
            root = buildtree();
            break;

        case 2:
            cout << "Building tree using level-order input...\n";
            buildfromlevelorder(root);
            break;

        case 3:
            cout << "Level Order Traversal:\n";
            levelorder(root);
            break;

        case 4:
            cout << "Preorder Traversal:\n";
            preorder(root);
            cout << endl;
            break;

        case 5:
            cout << "Inorder Traversal:\n";
            inorder(root);
            cout << endl;
            break;

        case 6:
            cout << "Postorder Traversal:\n";
            postorder(root);
            cout << endl;
            break;

        case 7:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
