#include <bits/stdc++.h>
using namespace std;

// Function to find the k-th smallest element
int ksmallestelement(int array[], int k, int n)
{
    priority_queue<int> pq; // created a max-heap; priority queue is also a heap
    // step 1:
    for (int i = 0; i < k; i++)
    {                      // processed the first k elements
        pq.push(array[i]); // pushed the first k elements
    }
    // step 2:
    for (int i = k; i <= n; i++)
    { // processed the remaining elements
        if (array[i] < pq.top())
        {                      // agar mera comming element pq k top se chota hai to
            pq.pop();          // top ko pop karo
            pq.push(array[i]); // aur comming element ko push kar do
        }
    }
    // step 3:
    return pq.top(); // heap ka top hamesha mera kth smallest element hota hai
}

int main()
{
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int array[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << "Enter the value of k (1-based index): ";
    cin >> k;

    if (k > n || k <= 0)
    {
        cout << "Invalid value of k. It should be between 1 and " << n << ".\n";
        return 1;
    }

    int result = ksmallestelement(array, k, n);
    cout << "The " << k << "-th smallest element is: " << result << endl;

    return 0;
}


// Enter the number of elements in the array: 5
// Enter the elements of the array: 7 10 4 20 15
// Enter the value of k (1-based index): 4
// The 4-th smallest element is: 15