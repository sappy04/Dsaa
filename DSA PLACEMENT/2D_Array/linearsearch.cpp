#include <bits/stdc++.h>
using namespace std;

int ispresent(vector<vector<int>> &array, int target, int row, int col)
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
    int targetrow = -1;
    int targetcol = -1;
    bool isreallypresent = false;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (array[i][j] == target)
            {
                isreallypresent = true;
                targetrow = i;
                targetcol = j;
                break;
            }
        }
    }
    if (isreallypresent == true)
    {
        cout << "your target is present in the array  at index(i,j)" << targetrow << " "<<targetcol << endl;
    }
    else
    {
        cout << "your target is not present in the array" << endl;
    }
    return 0;
}

int main()
{
    int row, col;
    cin >> row >> col; // 3 4
    vector<vector<int>> array(row, vector<int>(col));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> array[i][j]; // 1 2 3 4 5 6 7 8 9 10 11 12
        }
    }

    int target;
    cin >> target;
    ispresent(array, target, row, col);

    return 0;
}
