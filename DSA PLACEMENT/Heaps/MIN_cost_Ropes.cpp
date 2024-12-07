#include <bits/stdc++.h>
using namespace std;

class siuu
{
public:
    long long mincost(long long arr[], long long n)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq; // min heap bana diya
        for (int i = 0; i < n; i++)                                          // queue mai saare values daal diya
        {
            pq.push(arr[i]);
        }
        long long cost = 0;   // starting cost=0;
        while (pq.size() > 1) // jab tak queue mai ek value nahi reh jata karte jao
        {
            long long a = pq.top(); // min heap se least element nikal liya
            pq.pop();
            long long b = pq.top(); // min heap se phir se min heap nikal liya
            pq.pop();
            long long sum = a + b; // sum nikala
            cost += sum;           // cost mai store kiya
            pq.push(sum);          // sum ko queue mai daal diya
        }
        return cost;
    }
};

int main()
{
    siuu obj;
    long long n;
    cout << "Enter the number of elements: ";
    cin >> n;
    long long arr[n];
    cout << "Enter the elements: ";
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The minimum cost to connect the ropes is: " << obj.mincost(arr, n) << endl;

    return 0;
}
