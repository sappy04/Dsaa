#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    } // transpose with i and j+1
    for (int i = 0; i < n; i++)
    {

        reverse(matrix[i].begin(), matrix[i].end());

    } // reversed only row so i
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    } // print
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n)); // declared
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j]; // input
        }
    }
    cout << "your rotated matrix is: " << endl;
    rotate(matrix, n);
    return 0;
}