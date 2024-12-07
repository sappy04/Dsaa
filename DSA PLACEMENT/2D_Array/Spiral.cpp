#include <bits/stdc++.h>
using namespace std;
void printspiral(vector<vector<int>> &matrix, const string &input, int rows, int cols)
{
    int top = 0;
    int left = 0;
    int right = cols - 1;
    int bottom = rows - 1;
    int index = 0;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; ++i)
            matrix[top][i] = input[index++] - '0';
        top++;
        for (int i = top; i <= bottom; ++i)
            matrix[i][right] = input[index++] - '0';
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; --i)
                matrix[bottom][i] = input[index++] - '0';
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; --i)
                matrix[i][left] = input[index++] - '0';
            left++;
        }
    }
}
void printmatrix(const vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout<<endl;
    }
}
int main()
{
    int rows, cols;
    cin >> rows >> cols;
    string input;
    cin >> input;
    int total = rows * cols;
    if (input.length() != total)
    {
        cout << "Invalid Input" << endl;
    }
    vector<vector<int>> matrix(rows, vector<int>(cols));
    printspiral(matrix, input, rows, cols);
    printmatrix(matrix);
    return 0;
}

// void spiralPrint(int **input, int nRows, int nCols) {
//     int top = 0;           // Tracks the first row to process
//     int left = 0;          // Tracks the first column to process
//     int right = nCols - 1; // Tracks the last column to process
//     int bottom = nRows - 1; // Tracks the last row to process

//     while (top <= bottom && left <= right) {
//         // Print top row (left to right)
//         for (int i = left; i <= right; ++i) {
//             cout << input[top][i] << " ";
//         }
//         top++; // Move the top boundary down

//         // Print right column (top to bottom)
//         for (int i = top; i <= bottom; ++i) {
//             cout << input[i][right] << " ";
//         }
//         right--; // Move the right boundary left

//         // Print bottom row (right to left) if there are rows remaining
//         if (top <= bottom) {
//             for (int i = right; i >= left; --i) {
//                 cout << input[bottom][i] << " ";
//             }
//             bottom--; // Move the bottom boundary up
//         }

//         // Print left column (bottom to top) if there are columns remaining
//         if (left <= right) {
//             for (int i = bottom; i >= top; --i) {
//                 cout << input[i][left] << " ";
//             }
//             left++; // Move the left boundary right
//         }
//     }
// }
