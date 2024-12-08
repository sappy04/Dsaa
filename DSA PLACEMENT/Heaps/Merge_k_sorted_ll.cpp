#include <bits/stdc++.h>
using namespace std;

// Node class for linked list
class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int data) // Constructor
    {
        this->data = data;
        this->next = nullptr;
    }
};

// Box to represent a node in the priority queue
class listbox
{
public:
    int data;        // Node data
    ListNode *node;  // Pointer to the current node

    listbox(int data, ListNode *node) // Constructor
    {
        this->data = data;
        this->node = node;
    }
};

// Custom comparator for min-heap
class compare
{
public:
    bool operator()(listbox *a, listbox *b)
    {
        return a->data > b->data; // Min-heap: Smaller value will be at the top
    }
};

vector<int> mergeSortedLists(vector<ListNode *> &lists)
{
    priority_queue<listbox *, vector<listbox *>, compare> pq; // Min-heap

    // Push the first node of each linked list into the priority queue
    for (int i = 0; i < lists.size(); i++)
    {
        if (lists[i] != nullptr) // Only push if the list is not empty
        {
            listbox *temp = new listbox(lists[i]->data, lists[i]); // sabka first element nikal liya ll ka 
            pq.push(temp);
        }
    }

    vector<int> ans;      // To store the sorted result
    while (!pq.empty())   // While the queue has elements
    {
        listbox *temp1 = pq.top(); // Get the smallest element by min heap top
        pq.pop();

        ans.push_back(temp1->data); // Add the smallest element to the result

        if (temp1->node->next != nullptr) //current smallest ka next element jab tak ll k range tak hai
        {
            listbox *next = new listbox(temp1->node->next->data, temp1->node->next); // temp1->node matlab pehla node ll ka ,abhi temp->node->next->data means,next node ka data after the current smallest element
            pq.push(next);//current smallest k net value daal diya
        }
    }
    return ans; // Return the sorted result
}

int main()
{
    // Example input: 3 sorted linked lists
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(7);
    list1->next->next = new ListNode(9);

    ListNode *list2 = new ListNode(4);
    list2->next = new ListNode(5);
    list2->next->next = new ListNode(8);

    ListNode *list3 = new ListNode(2);
    list3->next = new ListNode(3);
    list3->next->next = new ListNode(6);

    vector<ListNode *> lists = {list1, list2, list3}; // Vector of linked lists

    vector<int> result = mergeSortedLists(lists);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
