#include <iostream>
using namespace std;

// Function to reverse the array
void reverse(int ans[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        swap(ans[start], ans[end]);
        start++;
        end--;
    }
}

// Function to sum two arrays representing numbers
void sumArrays(int A[], int N, int B[], int M) {
    int carry = 0; // Initialize carry
    int size = N + M; // Maximum size of the result
    int ans[size]; // Array to store the result
    int k = 0; // Index for the result array

    int i = N - 1; // Pointer for A
    int j = M - 1; // Pointer for B
    
    // Loop until both arrays are traversed
    while (i >= 0 && j >= 0) {
        int sum = A[i] + B[j] + carry; // Add digits and carry
        ans[k++] = sum % 10; // Store last digit of sum
        carry = sum / 10; // Update carry
        i--; // Move to next digit in A
        j--; // Move to next digit in B
    }

    // If there are remaining digits in A
    while (i >= 0) {
        int sum = A[i] + carry; // Add current digit from A
        ans[k++] = sum % 10; // Store last digit of sum
        carry = sum / 10; // Update carry
        i--; // Move to next digit in A
    }

    // If there are remaining digits in B
    while (j >= 0) {
        int sum = B[j] + carry; // Add current digit from B
        ans[k++] = sum % 10; // Store last digit of sum
        carry = sum / 10; // Update carry
        j--; // Move to next digit in B
    }

    // If there's still carry left
    while (carry > 0) {
        ans[k++] = carry % 10; // Store last digit of carry
        carry /= 10; // Update carry
    }

    // Reverse the result array to get the correct order
    reverse(ans, k);

    // Print the result
    for (int i = 0; i < k; i++) {
        cout << ans[i] << " "; // Output each digit
    }
    cout << endl; // New line after output
}

int main() {
    int n, n1;
    cin >> n >> n1; // Input sizes of A and B
    int A[n]; // Array for A
    int B[n1]; // Array for B

    // Input elements of A
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Input elements of B
    for (int i = 0; i < n1; i++) {
        cin >> B[i];
    }

    // Call the function to sum A and B
    sumArrays(A, n, B, n1);

    return 0;
}
