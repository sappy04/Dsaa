#include <iostream>
using namespace std;
int bsearch(int ar[], int l, int r, int x)
{
    while (l <= r)
    {
        int mid = (l + (r - l)) / 2;
        if (ar[mid] == x)
        {
            return mid;
        }
        else if (ar[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int output;
    int n;
    cout << "Enter the number of elements" << endl;
    cin >> n;
    int myarr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> myarr[i];
    }
    int f;
    cout << "Enter the number to be found" << endl;
    cin >> f;
    output = bsearch(myarr, 0, (n - 1), f);
    cout << "after sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << myarr[i] << " ";
    }
    if (output == -1)
    {
        cout << "no maatch" << endl;
    }
    else
    {
        cout << "maatch found" << endl;
    }
    return 0;
}