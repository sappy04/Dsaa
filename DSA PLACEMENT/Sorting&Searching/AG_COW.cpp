#include <iostream>
#include <algorithm>
using namespace std;

// Function to check if it is possible to place cows with at least 'dist' distance apart
bool isPossible(int array[], int n, int k, int dist) {
    int lastPosition = array[0];
    int count = 1; // Place the first cow

    for (int i = 1; i < n; i++) {
        if (array[i] - lastPosition >= dist) {
            count++; // Place the next cow
            lastPosition = array[i];
            if (count == k) {
                return true; // All cows are placed
            }
        }
    }
    return false; // Not all cows could be placed
}

// Function to find the maximum minimum distance
int aggressiveCows(int array[], int n, int k) {
    // Sort the stall positions
    sort(array, array + n);
    
    int start = 0; // Minimum possible distance
    int end = array[n - 1] - array[0]; // Maximum possible distance
    int result = -1;

    // Binary search for the maximum minimum distance
    while (start <= end) {
        int mid = start + (end - start) / 2; // Mid distance to check

        if (isPossible(array, n, k, mid)) {
            result = mid; // If possible, store this distance
            start = mid + 1; // Try for a bigger distance
        } else {
            end = mid - 1; // Try for a smaller distance
        }
    }
    return result; // Return the maximum minimum distance found
}

int main() {
    int n; // Number of stalls
    cin >> n;
    int array[n]; // Array to hold stall positions

    // Input the positions of the stalls
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int k; // Number of cows
    cin >> k;

    // Call the function and output the result
    int ans = aggressiveCows(array, n, k);
    cout << ans << endl;

    return 0;
}

/*
Example Input:
5
4 2 1 3 6
2

Output:
5
*/
