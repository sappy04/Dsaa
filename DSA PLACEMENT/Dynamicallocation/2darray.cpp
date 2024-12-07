#include <bits/stdc++.h>
using namespace std;
int main()
{
    int rows;
    int cols;
    cin >> rows;
    cin >> cols;  

    // creation done
    int **ar = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        ar[i]=new int[cols];
    }
    //input
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> ar[i][j];
        }
    }
    //output
    cout<<endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << ar[i][j]<<" ";
        }
        cout<<endl;
    }
    //free memory
    for(int i=0;i<rows;i++)
    {
        delete[] ar[i];
    }
    delete[] ar;
    return 0;
}