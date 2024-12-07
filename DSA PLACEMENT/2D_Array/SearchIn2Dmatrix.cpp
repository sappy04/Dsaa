#include <bits/stdc++.h>
using namespace std;
void searchyaar(vector<vector<int>> &matrix, int rows, int cols, int target)
{
    int start = 0;
    int end = (rows * cols) - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int element = matrix[mid / cols][mid % cols];
        if (element == target)
        {
            cout << "Element is present at index " << mid / cols << "," << mid % cols << endl;
            return;
        }
        else if (element > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout<<"element not found"<<endl;
}
int main()
{
    int rows;
    cin >> rows;
    int cols;
    cin >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols)); // declared
    for (int i = 0; i < rows; i++)                       // input
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int target;
    cin >> target;
    searchyaar(matrix, rows, cols, target);
    return 0;
}
// rowwise sorted matrix.
//output
// 1 3 5 7
// 10 11 16 20
// 23 30 34 60