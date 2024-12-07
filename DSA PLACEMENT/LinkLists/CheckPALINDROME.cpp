#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        cout << "Deleted " << this->data << endl;
    }
};

// Function to find the middle of the linked list
Node *mid(Node *&head) {
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL) // Ensuring fast->next is not NULL to avoid segmentation fault
    {
        fast = fast->next->next; // two step increment
        slow = slow->next;
    }
    return slow; // found mid
}

// Function to reverse the linked list
Node *reversedd(Node *head) // reversed bhai
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    while (curr != NULL) {
        next = curr->next; // saved the link-l
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to check if linked list is palindrome
bool Check(Node *&head) {
    if (head->next == NULL) {
        return true;
    }
    Node *midNode = mid(head); // mid element to mil gya
    Node *temp = midNode->next; // abhi reverse karna hai, pointer set kar diya
    midNode->next = reversedd(temp);

    Node *head1 = head;         // starting pe
    Node *head2 = midNode->next; // mid k baad se
    while (head2 != NULL) {
        if (head1->data != head2->data) {
            return false;
        }
        head1 = head1->next; // badaate raho pointer
        head2 = head2->next;
    }
    return true; // loop k bahar agaaya hai to pallindrome hai
}

int main() {
    // Creating a palindrome linked list: 1 -> 2 -> 3 -> 2 -> 1
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    // Checking if the linked list is palindrome
    if (Check(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    // Deleting the nodes to avoid memory leaks
    Node *temp = head;
    while (temp != NULL) {
        Node *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}
