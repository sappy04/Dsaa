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

// Helper function to link nodes in sorted order
Node *solve(Node *&head1, Node *&head2)
{
    if (head1->next == NULL)
    {
        head1->next = head2;//agar oehle element k baad kuch hai hi nahi then next list pe jorde wo(list2) bhi sorted hi hai
        return head1;
    }

    Node *curr1 = head1;
    Node *next1 = curr1->next;
    Node *curr2 = head2;
    Node *next2 = curr2->next;

    while (next1 != NULL && next2 != NULL) // next 1 last pointer hai list 1 ko to wo null nahi hona chahiye and curr2 list2 ka pointer ha wo bhi null nahi chahiye
    {
        if ((curr1->data <= curr2->data) && (curr2->data <= next1->data))
        {
            curr1->next = curr2; // list 1 k data ko list 2 k item se link kaar diya
            next2 = curr2->next; // link list ko save kara
            curr2->next = next1; // list 2 k item k next pointer list1 mai jor diya

            curr1 = curr2; // list 1 k pointer ko update kara
            curr2 = next2; // list 2 k pointer ko update kiya
        }
        else
        {
            curr1 = next1;       // just pointers age badha rahe hai
            next1 = next1->next; // yaha pe pointer badhane se mera list1 mai window samne shift hogya to compare with list2 ka next item se

            // If we reach the end of list1, attach the remainder of list2
            if (next1 == NULL)
            {
                curr1->next = curr2; // agar list1 ka next mera null ho jata hai then list 1 ko list 2 se jor do
                return head1;  // Corrected: Return head1 after merging the lists
            }
        }
    }
    return head1; // Corrected: Ensure head1 is returned at the end of solve
}

// Main merge function
Node *sortedmerge(Node *&head1, Node *&head2)
{
    if (head1 == NULL)
        return head2; // return second list
    if (head2 == NULL)
        return head1; // return 1st list if second is empty

    if (head1->data <= head2->data) // bade value ko list 1 mai daal
    {
        solve(head1, head2); // head1 solve function k current list 1 mai aaajayega
        return head1;
    }
    else
    {
        solve(head2, head1); // head2 solve function k current list 1 mai aaajayega
        return head2;
    }
}

int main()
{
    // Creating two sorted linked lists manually
    Node *head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);

    Node *head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);

    // Merging the lists
    Node *mergedHead = sortedmerge(head1, head2);

    // Printing merged list
    Node *temp = mergedHead;
    cout << "Merged list: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Deleting all nodes to avoid memory leaks
    temp = mergedHead;
    while (temp != NULL)
    {
        Node *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}
