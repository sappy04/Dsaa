#include <bits/stdc++.h>
using namespace std;

void searchMatrix(vector<vector<int>> &matrix, int rows, int cols, int target) {
    // Start from the top-right corner
    int i = 0, j = cols - 1;

    while (i < rows && j >= 0) {
        int element = matrix[i][j];

        // Found the target
        if (element == target) {
            cout << "Element is present at index " << i << "," << j << endl;
            return;
        }
        // If current element is greater than target, move left
        else if (element > target) {
            j--;
        }
        // If current element is smaller than target, move down
        else {
            i++;
        }
    }

    // If we reach here, the element is not found
    cout << "element not found" << endl;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    // Create the matrix
    vector<vector<int>> matrix(rows, vector<int>(cols));

    // Input the matrix values
    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Print the matrix
    cout << "The matrix is:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Input the target number we want to find
    int target;
    cout << "Enter the target element to search for: ";
    cin >> target;

    // Call the function to search for the target
    searchMatrix(matrix, rows, cols, target);

    return 0;
 }
 //outputs
// 3 3
// 1 4 7
// 2 5 8
// 3 6 9