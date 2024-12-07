#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *random;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }

    ~Node() {
        cout << "Deleted " << this->data << endl;
    }
};

Node *insertAttail(Node *&head, Node *&tail, int data) {
    Node *newNode = new Node(data);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

Node *copylist(Node *&head) {
    Node *clonehead = NULL;
    Node *clonetail = NULL;

    Node *temp = head; // original ko copy kiya
    while (temp != NULL) {
        insertAttail(clonehead, clonetail, temp->data);
        temp = temp->next;
    } // completed making my clone list

    // clone node add in between original lists
    Node *originalNode = head;
    Node *cloneNode = clonehead;
    while (originalNode != NULL && cloneNode != NULL) {
        Node *next = originalNode->next; // targeted the origianl link of th ll
        originalNode->next = cloneNode;  // mapping done(linear)
        originalNode = next;             // incrememented the originalnode pointer

        next = cloneNode->next;       // saved the clone linklist
        cloneNode->next = originalNode; // again established the cross connection
        cloneNode = next;         // incrememented the clone node pointer
    }

    // random pointer
    temp = head;
    while (temp != NULL) {
        if (temp->next != NULL) {
            if (temp->random != NULL) {
                temp->next->random = temp->random->next; // first random pointer acc to diagram
            } else {
                temp->next->random = temp->random;
            }
        }
        temp = temp->next->next;
    }

    // revert the changes
    originalNode = head;
    cloneNode = clonehead;
    while (originalNode != NULL && cloneNode != NULL) {
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;

        if (originalNode != NULL) {
            cloneNode->next = originalNode->next;
        }
        cloneNode = cloneNode->next;
    }
    return clonehead;
}
int main() {
    // Create a sample linked list with random pointers
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    // Link the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Set up random pointers
    head->random = third;     // 1's random pointer points to 3
    second->random = head;    // 2's random pointer points to 1
    third->random = fourth;   // 3's random pointer points to 4
    fourth->random = second;  // 4's random pointer points to 2

    // Display the original list
    cout << "Original list:\n";
    Node* temp = head;
    while (temp != NULL) {
        cout << "Node: " << temp->data;
        if (temp->random) {
            cout << ", Random points to: " << temp->random->data << endl;
        } else {
            cout << ", Random points to: NULL" << endl;
        }
        temp = temp->next;
    }

    // Make a copy of the list
    Node* cloneHead = copylist(head);

    // Display the cloned list
    cout << "\nCloned list:\n";
    temp = cloneHead;
    while (temp != NULL) {
        cout << "Node: " << temp->data;
        if (temp->random) {
            cout << ", Random points to: " << temp->random->data << endl;
        } else {
            cout << ", Random points to: NULL" << endl;
        }
        temp = temp->next;
    }

    // Clean up memory
    while (head != NULL) {
        Node* next = head->next;
        delete head;
        head = next;
    }
    while (cloneHead != NULL) {
        Node* next = cloneHead->next;
        delete cloneHead;
        cloneHead = next;
    }

    return 0;
}
