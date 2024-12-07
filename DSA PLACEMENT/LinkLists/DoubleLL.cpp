#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
        cout << "Memory freed for node with data " << data << endl;
    }
};

// traversing a linked list
void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// gives length of Linked List
int getLength(Node *&head)
{
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}
void insertAtHead(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);
    // empty list
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {

        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);
    if (tail == NULL)
    {

        tail = temp;
        head = temp;
    }
    else
    {

        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    // Insert at Start
    if (position <= 1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    // Traverse to the desired position or the last node
    while (cnt < position - 1 && temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL || temp->next == NULL) // insert at last
    {
        insertAtTail(head, tail, d); // Insert at the tail
        return;
    }

    // Otherwise, insert at the specified position in between
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = nodeToInsert; // temp->next ka jo value hai uska prev ka baat ho rahi hai.
    }

    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}
void deleteNode(Node *&head, Node *&tail, int position)
{
    // Deleting first or start node
    if (position == 1)
    {
        Node *temp = head;

        // If this is the only node in the list
        if (head->next == NULL)
        {
            head = NULL;
            tail = NULL; // Important: Update tail too
        }
        else
        {
            head = temp->next;
            head->prev = NULL;
            // Clean up
            temp->next = NULL;
            delete temp;
        }
    }
    else
    {
        // Deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position) // moved to current position
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        // Special case for last node
        if (curr->next == NULL) // if its the last node
        {
            tail = prev; // Update tail if deleting the last node
        }
        else
        {
            prev->next = curr->next;
            curr->next->prev = prev;
            curr->next = NULL;
            curr->prev = NULL;
            delete curr;
        }

    }
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    print(head);
    // cout << getLength(head) << endl;

    insertAtHead(head, tail, 11);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtHead(head, tail, 13);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtHead(head, tail, 8);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtTail(head, tail, 25);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtPosition(head, tail, 2, 100);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtPosition(head, tail, 1, 101);
    print(head);

    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtPosition(head, tail, 7, 102);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    deleteNode(head, tail, 1);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;
    return 0;
}