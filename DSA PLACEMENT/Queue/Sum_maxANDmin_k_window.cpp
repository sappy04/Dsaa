#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int k)
{
    deque<int> maxi; // To store indices of elements in decreasing order
    deque<int> mini; // To store indices of elements in increasing order

    // Addition of the first k-size window
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i]) // Maintain decreasing order
            maxi.pop_back();

        while (!mini.empty() && arr[mini.back()] >= arr[i]) // Maintain increasing order
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0;

    // Traverse the array for the rest of the windows
    for (int i = k; i < n; i++)
    {
        // Add the max and min of the previous window
        ans += arr[maxi.front()] + arr[mini.front()];

        // Remove elements out of the current window
        while (!maxi.empty() && maxi.front() <= i - k)
            maxi.pop_front();

        while (!mini.empty() && mini.front() <= i - k)
            mini.pop_front();

        // Add the current element
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }

    // Add the max and min of the last window
    ans += arr[maxi.front()] + arr[mini.front()];
    return ans;
}

int main()
{
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << "Sum of max and min in each window: " << solve(arr, 7, k) << endl;
    return 0;
}
