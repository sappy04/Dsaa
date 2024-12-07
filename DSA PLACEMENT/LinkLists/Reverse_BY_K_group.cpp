#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    // components
    int data;
    Node *next;    // class ka hi data type hoga
    Node(int data) // defining the datas declared in class by default constructor
    {
        this->data = data;
        this->next = NULL;
    }
    // ~Node()
    // {
    //     cout << "Deleting node with value: " << this->data << endl;
    //     // This will automatically handle NULL cases
    // }
};
Node *reverseby_kgroup(Node *&head,int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
    int cnt = 0; // to track k.
    // base case
    while (current != NULL && cnt < k) // reverse concept
    {
        next = current->next;//saved cthe ll
        current->next = prev;//connection toda
        prev = current;//to traverse
        current = next;//current ko current se ek age bada diya
        cnt++;
    }
    if (next != NULL) // recursive call
    {
        head->next = reverseby_kgroup(next, k);//next hi unreversed the ka pehla head hai
    }
    return prev;
}
int main()
{ // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    int k = 3; // Size of the group for reversing

    // Reverse the list in groups of k and print the result
    head = reverseby_kgroup(head, k);

    // Print the reversed list
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Free the memory
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}