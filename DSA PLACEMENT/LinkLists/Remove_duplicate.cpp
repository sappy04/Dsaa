#include <bits/stdc++.h>
using namespace std;

// Node class definition
class Node
{
public:
    int data;
    Node *next;

    // Constructor to initialize node
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Destructor for deletion
    ~Node()
    {
        cout << "deleted " << this->data << endl;
    }
};
Node *insertionSort(Node *head)
{
    if (head == NULL || head->next == NULL) // Agar list empty ya single node hai
        return head;

    Node *sorted = NULL; // Sorted list start mein khali hai

    Node *curr = head; // Current node original list se le rahe hain
    while (curr != NULL)
    {
        Node *next = curr->next; // Next node ko save kar rahe hain

        // Agar sorted list khali hai ya current node ka data first node se chhota hai
        if (sorted == NULL || sorted->data >= curr->data)
        {
            curr->next = sorted; // Sorted list ke start mein current node insert karte hain
            sorted = curr;       // Sorted list ko update karte hain
        }
        else
        {
            // Correct position find karte hain sorted list mein insert karne ke liye
            Node *temp = sorted;
            while (temp->next != NULL && temp->next->data < curr->data)
            {
                temp = temp->next; // Jab tak correct position nahi milta
            }
            curr->next = temp->next; // Correct position pe insert karte hain
            temp->next = curr;
        }

        curr = next; // Agle node pe move karte hain
    }

    return sorted; // Sorted list return karte hain
}

// Function to remove duplicates in a sorted linked list
Node *remove_dupli(Node *&head)
{
    Node *curr = head;

    // Traverse through the linked list
    while (curr != NULL && curr->next != NULL)
    {
        // If current node is equal to the next node, delete the next node
        if (curr->data == curr->next->data)
        {
            Node *temp = curr->next;       // store the duplicate node
            curr->next = curr->next->next; // remove the duplicate node from the list
            delete temp;                   // delete the duplicate node
        }
        else
        {
            curr = curr->next; // move to the next node if no duplicate
        }
    }

    return head;
}

// Function to insert nodes into the linked list
void insertAtTail(Node *&head, int data)
{
    Node *newNode = new Node(data);

    // If the list is empty, make the new node the head
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function
int main()
{
    Node *head = NULL;

    // Creating the linked list with input 1, 2, 2, 3, 3, 4
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 3);
    insertAtTail(head, 4);

    // Print the list before removing duplicates
    cout << "Original List: ";
    printList(head);

    // Remove duplicates
    remove_dupli(head);

    // Print the list after removing duplicates
    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
