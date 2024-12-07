#include <iostream>
using namespace std;

// Merge function to count inversions while merging
int mergeAndCount(int array[], int start, int mid, int end) {
    int i = start;     // Starting index for the left part
    int j = mid + 1;   // Starting index for the right part
    int k = 0;         // Index for temporary array
    int temp[end - start + 1];  // Temporary array to store merged elements
    int inversionCount = 0;     // To store inversion count

    // Merge the two parts into the temp array and count inversions
    while (i <= mid && j <= end) {
        if (array[i] <= array[j]) {
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
            // All the remaining elements in the left half (from i to mid) are greater than array[j]
            inversionCount += (mid - i + 1);
        }
    }

    // Copy remaining elements from the left part
    while (i <= mid) {
        temp[k++] = array[i++];
    }

    // Copy remaining elements from the right part
    while (j <= end) {
        temp[k++] = array[j++];
    }

    // Copy the merged array back into the original array
    for (int i = start; i <= end; i++) {
        array[i] = temp[i - start];
    }

    return inversionCount;
}

// Function for merge sort and counting inversions using array indices
int mergeSortAndCount(int array[], int start, int end) {
    int inversionCount = 0;
    
    if (start < end) {
        int mid = start + (end - start) / 2;

        // Recursively sort the left and right halves and count inversions
        inversionCount += mergeSortAndCount(array, start, mid);
        inversionCount += mergeSortAndCount(array, mid + 1, end);

        // Merge the sorted halves and count cross-inversions
        inversionCount += mergeAndCount(array, start, mid, end);
    }

    return inversionCount;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int array[1000];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    // Perform merge sort and count inversions
    int inversionCount = mergeSortAndCount(array, 0, n - 1);

    // Output sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Output the inversion count
    cout << "Number of inversions: " << inversionCount << endl;

    return 0;
}
