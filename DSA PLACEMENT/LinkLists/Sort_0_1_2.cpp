#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        cout << "deleted" << this->data << endl;
    }
};
Node *insertAttail(Node *tail, Node *curr) // tail pe current node ko dalo
{
    tail->next = curr;
    tail = curr;
    return tail; // return to kar mere bhai
}
Node *sortkaro(Node *&head)
{
    Node *zerohead = new Node(-1); // dummy node for zeros
    Node *zerotail = zerohead;     // pointing at the same node
    Node *onehead = new Node(-1);  // dummy node for ones
    Node *onetail = onehead;
    Node *twohead = new Node(-1); // dummy node for twos
    Node *twotail = twohead;

    Node *curr = head;
    // Traverse and segregate the nodes into three lists
    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            zerotail = insertAttail(zerotail, curr);
        }
        else if (curr->data == 1)
        {
            onetail = insertAttail(onetail, curr);
        }
        else if (curr->data == 2)
        {
            twotail = insertAttail(twotail, curr);
        }
        curr = curr->next;
    }

    // Merging the lists
    if (onehead->next != NULL)
    {
        zerotail->next = onehead->next;
    }
    else
    {
        zerotail->next = twohead->next;
    }

    onetail->next = twohead->next;
    twotail->next = NULL;

    // Update head to point to the start of the sorted list
    head = zerohead->next;

    // Deleting the dummy nodes
    delete zerohead;
    delete onehead;
    delete twohead;

    return head;
}
int main()
{
    // Create nodes manually
    Node *n1 = new Node(2);
    Node *n2 = new Node(0);
    Node *n3 = new Node(1);
    Node *n4 = new Node(2);
    Node *n5 = new Node(0);
    Node *n6 = new Node(2);
    Node *n7 = new Node(1);

    // Link nodes to form a linked list
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;

    // Set the head to the first node
    Node *head = n1;

    cout << "Original list: ";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Sort the list containing 0s, 1s, and 2s
    head = sortkaro(head);

    cout << "Sorted list: ";
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Deleting the nodes
    temp = head;
    while (temp != NULL)
    {
        Node *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}