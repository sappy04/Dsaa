#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    int row;
    int col;
    node(int data, int row, int col)
    {
        this->data = data; // Use 'this->' to assign class member variables
        this->row = row;
        this->col = col;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data; // Min-heap comparison
    }
};

int smallestrangefromkthsortedlists(vector<vector<int>> &array, int k, int n) // array elements hai+kitne arrays hai+per array ka size kitna hai(no.of cols)
{
    int mini = INT_MAX; // max min dummy value
    int maxi = INT_MIN;
    priority_queue<node *, vector<node *>, compare> pq; // min heap

    for (int i = 0; i < k; i++) // pehla col ko update kar diya
    {
        int element = array[i][0]; // first element utha liya mai
        maxi = max(maxi, element); // max element nikal liya pehle col ka
        mini = min(mini, element); // same for mini
        pq.push(new node(element, i, 0));//push kar diya saare 1st col k values ko heap mai
    }

    int start = mini; // for range purpose
    int end = maxi;

    while (!pq.empty()) // jab tak mera queue khali nahi hai karte raho
    {
        node *smallest = pq.top(); // smallest nikal liya heap se
        pq.pop();

        mini = smallest->data;         // mini ko original se update kiya
        if (maxi - mini < end - start) // agar range se chota hai to
        {                              // range ko update karo
            start = mini;
            end = maxi;
        }

        if (smallest->col + 1 < n) // smallest k baad ka next element nikala for processing
        {
            maxi = max(maxi, array[smallest->row][smallest->col + 1]);
            pq.push(new node(array[smallest->row][smallest->col + 1], smallest->row, smallest->col + 1));
        }
        else // range mai hi lie nahi karta
        {
            break;
        }
    }

    cout << "Smallest range: [" << start << ", " << end << "]" << endl; // Print the range
    return (end - start + 1); // Return the range length
}

int main()
{
    int k, n;
    cout << "Enter number of arrays (k) and size of each array (n): ";
    cin >> k >> n;

    vector<vector<int>> array(k, vector<int>(n)); // Initialize k x n matrix
    cout << "Enter the elements of the arrays (row-wise):" << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> array[i][j]; // Input elements row-wise
        }
    }

    int rangeLength = smallestrangefromkthsortedlists(array, k, n);
    cout << "Length of the smallest range is: " << rangeLength << endl;

    return 0;
}

// Enter the elements of the arrays (row-wise):
// 1 3 5 7 9
// 2 4 6 8 10
// 0 9 10 11 12
// Smallest range: [8, 9]
// Length of the smallest range is: 2
