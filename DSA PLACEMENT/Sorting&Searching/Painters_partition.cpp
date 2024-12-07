#include<iostream>
using namespace std;

// Function to check if a solution exists where painters can paint all boards
// within the given time limit `mid`
bool isPossible(int arr[], int n, int m, int mid) {
    int painters = 1;
    int boardsum = 0;

    for (int i = 0; i < n; i++) {
        if (boardsum + arr[i] <= mid) {
            boardsum += arr[i]; // Add the board length to the current painter's sum
        } else {
            painters++; // Assign new painter
            if (painters > m) {
                return false; // More painters needed than available
            }
            boardsum = arr[i]; // Start new painter with this board
        }
    }
    return true;
}

// Function to find the minimum time to paint all boards
int paintersPartition(int arr[], int n, int m) {
    int start = 0;
    int sum = 0;

    // Calculate the total sum of board lengths
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int end = sum;
    int result = -1;

    // Apply binary search to find the minimum possible maximum time
    while (start <= end) {
        int mid = start + (end - start) / 2;

        // Check if it's possible to allocate boards such that no painter paints more than `mid` length
        if (isPossible(arr, n, m, mid)) {
            result = mid; // Valid solution, try to find a smaller maximum time
            end = mid - 1;
        } else {
            start = mid + 1; // Increase the limit and try again
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    // Input the length of each board
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int m;
    cin >> m; // Number of painters

    int ans = paintersPartition(arr, n, m); // Call the function
    cout << ans << endl; // Output the result

    return 0;
}

/*
Example Input:
4
5 5 5 5
2

Output:
60
*/
