#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int array[100];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int unique = 0;
    for (int i = 0; i < n; i++)
    {
        unique ^= array[i];
    }
    cout << "unique is: " << unique << endl;

    return 0;
}