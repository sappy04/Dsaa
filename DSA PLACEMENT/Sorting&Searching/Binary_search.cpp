#include <bits/stdc++.h>
using namespace std;
void binary(int a[], int n, int search)
{
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == search)
        {
            cout << "elemnet found at position " << mid << endl;
            return;
        }
        else if (a[mid] > search)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << "element is not found: " << endl;
}
int main()
{
    int n;
    cin >> n; // size
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    } // array
    int search; // search
    cin >> search;
    binary(a, n, search);
    return 0;
}
// binary

// 5
// 0 9 7 5 6