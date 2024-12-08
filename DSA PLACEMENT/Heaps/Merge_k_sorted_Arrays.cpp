#include <bits/stdc++.h>
using namespace std;

class arraybox // ye wo box hai jab kth sorted elements ko sath sath rakhte hai
{
public:
    int data;
    int i;                                // Row index
    int j;                                // Column index
    arraybox(int data, int row, int cols) // Constructor
    {
        this->data = data;
        i = row;
        j = cols;
    }
};
// priority queue by default mera max heap deta hai to min heap bananen k liye mujhe custom banana padhega
class compare // my min heap comparator
{
public:
    bool operator()(arraybox *a, arraybox *b) // 2 2 elements leke kaam kar raha hai jaise pehla 2 elements in a column inka chota value ko ans mai push kardega and larger a banega aur next wala element b banaega
    {
        return a->data > b->data;
    }
};

vector<int> sortedarray(vector<vector<int>> &array, int k)
{
    priority_queue<arraybox *, vector<arraybox *>, compare> pq; // Min-heap

    for (int i = 0; i < k; i++) // saare k arrays ka value daal diya maine array mai
    {
        if (!array[i].empty()) // Only push if the array is not empty
        {
            arraybox *temp = new arraybox(array[i][0], i, 0); // pehle col ka saare k arrays ka value daal diya
            pq.push(temp);
        }
    }

    vector<int> ans;      // ismai sorted way mai saare values daalenge
    while (pq.size() > 0) // jab tak mera queue mai values hai
    {
        arraybox *temp1 = pq.top(); // top ko pakar liya for next element ko pakarne k liye
        pq.pop();
        ans.push_back(temp1->data); // Current smallest value ko result array mai daal diya

        int i = temp1->i; // next element ko pakar liya ussi array ka
        int j = temp1->j;

        if (j + 1 < array[i].size()) // j+1 matlab mai ussi array k next element ko pakar raha hoon
        {
            arraybox *next = new arraybox(array[i][j + 1], i, j + 1); // ismai maine ussi array k next waale element ko store kar liya
            pq.push(next);                                            // min heap mai daal diya mai
        }
    }
    return ans; // sorted array ko return kardo
}

int main()
{
    // Example input
    vector<vector<int>> array = {
        {1, 7, 9},
        {4, 5, 8},
        {2, 3, 6}};

    int k = array.size(); // Number of arrays

    vector<int> result = sortedarray(array, k);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
