#include <iostream>
using namespace std;

int findPeakElement(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    // Binary Search Loop
    while (start < end) {
        int mid = start + (end - start) / 2;

        // Step 1: Check if mid is the peak
        if (arr[mid] < arr[mid + 1]) {
            // If we are in the increasing part, the peak lies on the right side
            start = mid + 1;
        } else {
            // If we are in the decreasing part, the peak lies on the left side (or mid could be the peak)
            end = mid;
        }
    }

    // When start == end, we have found the peak
    return start;  // or return end, since start == end
}

int main() {
    int arr[] = {1, 3, 8, 12, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int peakIndex = findPeakElement(arr, n);
    cout << "The peak element is at index: " << peakIndex << endl;
    cout << "The peak element is: " << arr[peakIndex] << endl;

    return 0;
}
