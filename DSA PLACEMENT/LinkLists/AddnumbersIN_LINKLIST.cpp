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
        cout << "Deleted " << this->data << endl;
    }
};

// Function to reverse a linked list
Node *reversedd(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next; // saved the link-l
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to insert a node at the tail of the linked list
Node *insertAttail(Node *&head, Node *&tail, int value)
{
    Node *temp = new Node(value); // Create a new node with the given value
    if (head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
    return head; // Return head to keep track of the list's start
}

// Function to add two reversed linked lists
Node *add(Node *&first, Node *&second)
{
    int carry = 0;
    Node *anshead = NULL;
    Node *anstail = NULL;

    while (first != NULL || second != NULL || carry != 0)
    {
        int val1;

        if (first != NULL)
        {
            val1 = first->data; // If second is not NULL, assign its data to val2
        }
        else
        {
            val1 = 0; // If second is NULL, assign 0 to val2
        }
        int val2;

        if (second != NULL)
        {
            val2 = second->data; // If second is not NULL, assign its data to val2
        }
        else
        {
            val2 = 0; // If second is NULL, assign 0 to val2
        }

        int sum = carry + val1 + val2;
        int digit = sum % 10;                  // got the last digit
        insertAttail(anshead, anstail, digit); // create a node and add it to the answer linked list
        carry = sum / 10;

        if (first != NULL)
        {
            first = first->next;
        }
        if (second != NULL)
        {
            second = second->next;
        }
    }
    return anshead;//returning the head of the answer list
}

// Wrapper function to add two linked lists representing numbers
Node *Addit(Node *&list1, Node *&list2)
{
    Node *first = reversedd(list1);
    Node *second = reversedd(list2);
    Node *ans = add(first, second);
    ans = reversedd(ans); // Reverse the result to get the final answer in correct order
    return ans;
}

// Helper function to print a linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Creating two linked lists: (e.g., representing numbers 123 and 456)
    Node *list1 = new Node(1);
    list1->next = new Node(2);
    // list1->next->next = new Node(3);

    Node *list2 = new Node(4);
    list2->next = new Node(5);
    list2->next->next = new Node(6);

    // Adding two lists
    Node *result = Addit(list1, list2);

    // Printing the result list
    cout << "Result of addition: ";
    printList(result);

    // Deleting nodes to prevent memory leaks
    Node *temp = result;
    while (temp != NULL)
    {
        Node *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}
