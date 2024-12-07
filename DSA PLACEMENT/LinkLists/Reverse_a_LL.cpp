#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data) // constructor to initialize data and next
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Deleting node with value: " << this->data << endl;
    }
};

// Function to reverse the linked list
Node* reversell(Node* head)
{
    if (head == NULL || head->next == NULL)
    {
        cout << "List is either empty or has only one node." << endl;
        return head;
    }

    Node *prev = NULL;
    Node *current = head;
    Node *forward = NULL;

    while (current != NULL)
    {
        forward = current->next;  // save the next node
        current->next = prev;     // reverse the current node's link
        prev = current;           // move prev to current node
        current = forward;        // move to the next node in the list
    }

    return prev;  // prev will be the new head of the reversed list
}

int main()
{
    // Creating a sample linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Reversing the linked list
    head = reversell(head);

    // Printing the reversed list
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Deleting the list to free memory
    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
