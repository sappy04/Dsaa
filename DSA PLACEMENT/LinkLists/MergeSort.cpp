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
};

// Function to find the middle of the linked list
Node *findmid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {                            // Ensuring fast->next is not NULL to avoid segmentation fault
        fast = fast->next->next; // two step increment
        slow = slow->next;
    }
    return slow; // found mid
}

// Function to merge two sorted linked lists
Node *merge(Node *left, Node *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    Node *ans = new Node(-1); // to store merged sorted link list
    Node *temp = ans;         // temp k through pure list ko access karunga

    while (left != NULL && right != NULL)
    { // jab tak donno hi null nahi hai
        if (left->data < right->data)
        {                      // chote se badha arrange karenge
            temp->next = left; // jor diya left ko answer list mai
            left = left->next; // increment
        }
        else
        {
            temp->next = right; // jor diya right ko answer list mai

            right = right->next; // increment
        }
        temp = temp->next;
    }

    if (left != NULL)
    {
        temp->next = left;
    }
    else
    {
        temp->next = right;
    }

    Node *result = ans->next; // ek ke karke answer ko items ko bara raha hoon
    delete ans;               // temporary node ko delete karenge
    return result;            // return merged answer
}

// Function to apply merge sort on linked list
Node *mergesort(Node *head)
{
    if (head == NULL || head->next == NULL) // base case
        return head;

    Node *mid = findmid(head); // found the mid
    Node *left = head;         // left half
    Node *right = mid->next;   // right half
    mid->next = NULL;          // connection toda

    left = mergesort(left);   // merge sort kar diya left part pe
    right = mergesort(right); // merge sort kar diya right part pe

    // Ab result store karo
    Node *ans = merge(left, right);
    return ans;

}
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

int main()
{
    // Example usage
    Node *head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);

    cout << "Original List: ";
    printList(head);

    head = mergesort(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node *next;

//     Node(int data) {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// // Function to find the middle of the linked list
// Node *findmid(Node *head) {
//     Node *slow = head;
//     Node *fast = head->next; // Fast starts at head->next to split correctly

//     while (fast != NULL && fast->next != NULL) {
//         fast = fast->next->next;
//         slow = slow->next;
//     }
//     return slow; // Mid found correctly
// }

// // Merge two sorted linked lists
// Node *merge(Node *left, Node *right) {
//     Node *ans = new Node(-1); // Dummy node to start merged list
//     Node *temp = ans;

//     while (left != NULL && right != NULL) {
//         if (left->data < right->data) {
//             temp->next = left; // Link smaller node
//             left = left->next;
//         } else {
//             temp->next = right; // Link smaller node
//             right = right->next;
//         }
//         temp = temp->next; // Move temp pointer forward
//     }

//     // Attach remaining nodes
//     if (left != NULL) temp->next = left;
//     else temp->next = right;

//     Node *result = ans->next; // Skip dummy node
//     delete ans;               // Clean up dummy node
//     return result;
// }

// // Merge Sort for linked list
// Node *mergesort(Node *head) {
//     if (head == NULL || head->next == NULL) {
//         return head; // Base case
//     }

//     Node *mid = findmid(head);
//     Node *left = head;
//     Node *right = mid->next;
//     mid->next = NULL; // Split the list

//     left = mergesort(left); // Recursively sort left half
//     right = mergesort(right); // Recursively sort right half

//     return merge(left, right); // Merge sorted halves
// }

// // Helper function to print linked list
// void printList(Node *head) {
//     Node *temp = head;
//     while (temp != NULL) {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// int main() {
//     // Creating a linked list: 5 -> 3 -> 8 -> 1
//     Node *head = new Node(51);
//     head->next = new Node(3);
//     head->next->next = new Node(8);
//     head->next->next->next = new Node(1);
//     head->next->next->next->next = new Node(5);

//     cout << "Original List: ";
//     printList(head); // Print original list

//     head = mergesort(head); // Sort the linked list

//     cout << "Sorted List: ";
//     printList(head); // Print the sorted linked list

//     return 0;
// }
