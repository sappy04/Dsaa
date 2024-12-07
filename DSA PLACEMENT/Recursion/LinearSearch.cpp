#include <bits/stdc++.h>
using namespace std;
bool searching(int array[], int n,int target)
{
    if (n == 0)
    {
        return false;
    }
    if(array[0]==target)
    {
        return array[0];
    }
    return searching(array+1,n-1,target);
    
}
int main()
{
    int n;
    cin >> n;
    int array[100];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int target;
    cin >> target;
    int ans = searching(array, n,target);
    if (ans == 1)
    {
        cout << "element found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    return 0;
}