#include <iostream>
using namespace std;

void generateSubsets(int nums[], int current[], int n, int index, int curSize) {
    // Print the current subset
    for (int i = 0; i < curSize; i++) {
        cout << current[i] << " ";
    }
    cout << endl;

    // Try including each element starting from the current index
    for (int i = index; i < n; i++) {
        // Include nums[i] in the current subset
        current[curSize] = nums[i];
        // Recursively generate further subsets
        generateSubsets(nums, current, n, i + 1, curSize + 1);
    }
}

void subsets(int nums[], int n) {
    int current[100]; // Fixed-size array to hold current subset (assuming max size 100)
    generateSubsets(nums, current, n, 0, 0);
}

int main() {
    int nums[] = {1, 2, 3};  // Example input array
    int n = sizeof(nums) / sizeof(nums[0]);
    subsets(nums, n);
    return 0;
}
