#include<bits/stdc++.h>
using namespace std;
// Function to find the next smaller element for each element in the array
void nextSmallerElement(int arr[], int n, int next[]) {
    stack<int> s; 
    for (int i = n - 1; i >= 0; i--) {
        // Store the current element in a variable
        int currentElement = arr[i];
        
        // Pop elements from stack that are greater than or equal to current element
        while (!s.empty() && arr[s.top()] >= currentElement) {
            s.pop();
        }
        
        // If stack is not empty, the top of the stack is the next smaller element
        if (!s.empty()) {
            next[i] = s.top();
        } else {
            next[i] = n; // No smaller element to the right, so assign n (out of bounds)
        }
        // Push the current element's index onto the stack
        s.push(i);
    }
}

// Function to find the previous smaller element for each element in the array
void prevSmallerElement(int arr[], int n, int prev[]) {
    stack<int> s;
    for (int i = 0; i < n; i++) {
        // Store the current element in a variable
        int currentElement = arr[i];
        
        // Pop elements from stack that are greater than or equal to current element
        while (!s.empty() && arr[s.top()] >= currentElement) {
            s.pop();
        }
        
        // If stack is not empty, the top of the stack is the previous smaller element
        if (!s.empty()) {
            prev[i] = s.top();
        } else {
            prev[i] = -1; // No smaller element to the left, so assign -1
        }
        // Push the current element's index onto the stack
        s.push(i);
    }
}

// Function to calculate the largest rectangle area in a histogram
int largestRectangleArea(int arr[], int n) {
    int next[n]; // To store the next smaller element indices
    int prev[n]; // To store the previous smaller element indices

    // Find next and previous smaller elements for the histogram
    nextSmallerElement(arr, n, next);
    prevSmallerElement(arr, n, prev);

    int maxArea = INT_MIN; // Initialize maximum area with a very small number

    // Calculate the area for each bar
    for (int i = 0; i < n; i++) {
        int height = arr[i]; // Height of the current bar (explicitly storing the current element)
        int width = next[i] - prev[i] - 1; // Width is the distance between PSE and NSE
        int area = height * width; // Calculate the area of rectangle
        maxArea = max(maxArea, area); // Update the maximum area
    }

    return maxArea; // Return the maximum area found
}

int main() {
    int arr[] = {2, 1, 5, 6, 2, 3}; // Heights of the histogram
    int n = sizeof(arr) / sizeof(arr[0]); // Size of the array

    cout << "Largest Rectangle Area: " << largestRectangleArea(arr, n) << endl;

    return 0;
}
