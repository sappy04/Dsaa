#include <iostream>

using namespace std;

bool uniqueCounts(int arr[], int size) {
    // Step 1: Find the biggest number in the array
    int max = arr[0]; 
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i]; 
        }
    }

    // Step 2: Create a counting array to count occurrences of each number
    int countArr[max + 1] = {0}; 

    // Step 3: Count each number's occurrences
    for (int i = 0; i < size; i++) {
        countArr[arr[i]]++; 
    }

    // Step 4: Check if all counts are unique
    // We'll create another array to track how often each count occurs
    int seenCounts[size + 1] = {0};  // This will track how often a count appears

    for (int i = 0; i <= max; i++) {
        if (countArr[i] > 0) {  // Only care about numbers that appeared
            seenCounts[countArr[i]]++;  // Increment the count for this frequency
        }
    }

    // Step 5: If any count appears more than once, return false
    for (int i = 0; i <= size; i++) {
        if (seenCounts[i] > 1) {  // If any count is repeated, return false
            return false;
        }
    }

    return true;  // If no counts are repeated, return true
}

int main() {
    // Input the size of the array
    int n;
    cin >> n;

    // Declare array of size n
    int arr[n]; 

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call function to check if all counts are unique
    if (uniqueCounts(arr, n)) {  // Pass n directly as the size
        cout << "All counts are unique." << endl;
    } else {
        cout << "Counts are not unique." << endl;
    }

    return 0;
}
