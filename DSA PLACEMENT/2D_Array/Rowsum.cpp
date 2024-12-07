#include <bits/stdc++.h>
using namespace std;
void yoursum(vector<vector<int>> &array, int row, int col)
{
    cout << "your array is: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum = sum + array[i][j];
        }
        cout << "sum of row " << i + 1 <<":"<< sum << endl;
    }
}
int main()
{
    int row, col;
    cin >> row >> col;
    vector<vector<int>> array(row, vector<int>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> array[i][j];
        }
    }
    yoursum(array, row, col);
    return 0;
}


//COLSUM

// #include <bits/stdc++.h>
// using namespace std;
// void yoursum(vector<vector<int>> &array, int row, int col)
// {
//     cout << "your array is: " << endl;
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             cout << array[i][j] << " ";
//         }
//         cout << endl;
//     }
//     for (int i = 0; i < row; i++)
//     {
        
//         int sum = 0;
//         for (int j = 0; j < col; j++)
//         {
//             sum = sum + array[j][i];
//         }
//         cout << "sum of cols " << i + 1 << ":" << sum << endl;
//     }
// }
// int main()
// {
//     int row, col;
//     cin >> row >> col;
//     vector<vector<int>> array(row, vector<int>(col));
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             cin >> array[i][j];
//         }
//     }
//     yoursum(array, row, col);
//     return 0;
// }