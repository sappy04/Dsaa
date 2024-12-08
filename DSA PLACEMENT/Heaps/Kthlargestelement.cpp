#include <bits/stdc++.h>
using namespace std;

int kthlargestsubarray(vector<int>& array, int k) {
    priority_queue<int, vector<int>, greater<int>> pq; // created the min heap
    int n = array.size(); // size of the input array

    for (int i = 0; i < n; i++) // finding out the entire subarray sums
    {
        int sum = 0;
        for (int j = i; j < n; j++) // calculate subarray sums from i to j
        {
            sum = sum + array[j]; // saare subarrays ka sum nikal liya
            if (pq.size() < k) // agar k th element hi nahi hai phir kya hi compare kare, sum ko daal do
            {
                pq.push(sum);
            }
            else
            {
                if (sum > pq.top()) // agar mera sum pq k top se badha hai to insert karna padhega, pop karke daal do sum ko min heap mai
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top(); // kth largest sum
}

int main() {
    vector<int> array = {10, -10, 20, -40, 30}; // example input array
    int k = 3; // kth largest subarray sum to find

    cout << "The " << k << "rd largest subarray sum is: " << kthlargestsubarray(array, k) << endl;

    return 0;
}
