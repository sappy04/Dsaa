#include <bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>> &matrix)
{
    int n = matrix.size();       // ye mai row ka size liya
    int m = matrix[0].size();    // ye mai col ka size liya
    vector<int> rowcaught(n, 0); // ek row ko track karne k liye structure
    vector<int> colcaught(m, 0); // same for col...basically ek dummy matrix create ho jata hai of zero
    for (int rows = 0; rows < n; rows++)
    {
        for (int cols = 0; cols < m; cols++)
        {
            if (matrix[rows][cols] == 0)
            {
                rowcaught[rows] = 1; // mark kar diya row ko
                colcaught[cols] = 1; // same for col
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (rowcaught[i] == 1 || colcaught[j] == 1) // marker ko trace kiya
            {
                matrix[i][j] = 0; // aur replace kar diya
            }
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};

    setZeros(matrix);

    // Output the updated matrix
    for (const auto &row : matrix)
    {
        for (int elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
