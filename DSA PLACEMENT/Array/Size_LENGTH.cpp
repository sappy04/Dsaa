#include <bits/stdc++.h>
using namespace std;
int main()
{
    int array[103] = {2, 0, 3, 4};
    int size = sizeof(array) / sizeof(int);
    cout << size << endl;
    int count=0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] != 0) //
        {
            count++;
        }
    }
    cout << "original length is: " << count << endl;

    return 0;
}