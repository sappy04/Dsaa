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
    ~Node()
    {
        cout << "Deleting node with value: " << this->data << endl;
        delete next; // This will automatically handle NULL cases
    }
};
void insertAthead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head; // made the address to initial head pointer
    head = temp;       // shifted headed pointed to temp
}
void insertAttail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp; // attached the coonection of new node with exsisting tail
    tail = temp;       // renamed tail to temp
}
void inserAtposition(Node *&head, Node *&tail, int position, int data)
{
    // insert at head
    if (position == 1)
    {
        insertAthead(head, data); // function call
        return;                   // niklo hogaya kaam
    }
    // node jo ghusega
    Node *temp = head; // head se start nahi karne se front back ka lafra hoga
    int cnt = 1;

    while (cnt < position - 1 && temp != NULL) // temp ko us position tak le janeka process
    {
        temp = temp->next;
        cnt++;
    }
    Node *toInsertdata = new Node(data);
    toInsertdata->next = temp->next;
    temp->next = toInsertdata;

    // insert at last
    if (temp->next == NULL) //
    {
        insertAttail(tail, data);
        return; // hogaya kaam bhago
    }
    
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL) //
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void deleteNode(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = head; // safety
        head = head->next;
        temp->next = NULL;
        delete temp; // free karo

        if (head == NULL) // head khali to tail khali
        {
            tail = NULL;
        }
    }
    else
    {
        Node *current = head; // traversal start to bhai sirf head se hi hogaa
        Node *prev = NULL;    // co pointer
        int cnt = 1;
        while (cnt < position && current != NULL)
        {                            // cnt<position prev sahi position pe hai
            prev = current;          // sath sath move karte hai
            current = current->next; // is step pe hi current abhi prev se ek age badh gaya
            cnt++;
        }
        prev->next = current->next; // channel establish hoye gache
        if (current->next == NULL)  // jodi the element to be deleted is end element and points null then
        {
            tail = prev; // mark prev as tail
        } // if not end node then
        current->next = NULL; // deleted eelement ka link tora maine
        delete current;
    }
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    insertAthead(head, 5);
    insertAttail(tail, 20);
    inserAtposition(head, tail, 2, 15);

    cout << "Linked list before deletion:" << endl;
    print(head);

    deleteNode(head, tail, 4); // Deleting node at position 3

    cout << "Linked list after deletion:" << endl;
    print(head);

    cout << "Head data is: " << head->data << endl;
    cout << "Tail data is: " << tail->data << endl;
    return 0;
}