#include <iostream>
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
        cout << "Deleting node with value: " << this->data << endl;
    }
};

// Function to find the middle node using length-based approach
Node* middle(Node* head)
{
    if (head == NULL)
    {
        return NULL; // If the list is empty, return NULL
    }

    // Step 1: Calculate the length of the linked list
    int len = 0;
    Node* temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next; // Move to the next node
    }

    // Step 2: Calculate the middle index based on even or odd length
    int mid;
    if (len % 2 == 0) // Even length
    {
        mid = (len / 2)
        ;  // First element of the second half
    }
    else // Odd length
    {
        mid = len / 2;  // Exact middle element
    }

    // Step 3: Traverse the list again to find the middle node
    temp = head;
    for (int i = 0; i < mid; i++)
    {
        temp = temp->next;  // Move to the next node until mid is reached
    }

    return temp;  // Return the middle node
}

int main()
{
    // Test case 1: Linked list with even number of nodes: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    head1->next->next->next->next->next = new Node(6);

    // Test case 2: Linked list with odd number of nodes: 1 -> 2 -> 3 -> 4 -> 5
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = new Node(4);
    head2->next->next->next->next = new Node(5);

    // Finding and printing the middle nodes for both test cases
    Node* mid1 = middle(head1);
    if (mid1 != NULL)
    {
        cout << "The middle node for even length list is: " << mid1->data << endl;  // Should print 4
    }

    Node* mid2 = middle(head2);
    if (mid2 != NULL)
    {
        cout << "The middle node for odd length list is: " << mid2->data << endl;  // Should print 3
    }

    // Free memory for both linked lists
    while (head1 != NULL)
    {
        Node* temp = head1;
        head1 = head1->next;
        delete temp;
    }

    while (head2 != NULL)
    {
        Node* temp = head2;
        head2 = head2->next;
        delete temp;
    }

    return 0;
}
