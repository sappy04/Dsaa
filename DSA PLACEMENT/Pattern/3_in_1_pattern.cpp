#include <iostream>
using namespace std;
int main()
{
    for (int i = 5; i >= 1; i--)
    {
        for (int j = 1; j <= (i); j++)
        {
            cout << j << " ";
        }
        for(int k=1;k<=(5-i)*2;k++)
        {
            cout<<"*"<<" ";
        }
        for (int j = i; j >= (1); j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}