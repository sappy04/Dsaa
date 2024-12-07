#include <bits/stdc++.h>
using namespace std;
int thesum(int array[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return array[0];
    }
    int sum = 0;

    sum = array[0] + thesum(array + 1, n - 1);

    return sum;
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
    int ans = thesum(array, n);
    cout << ans << endl;
    return 0;
}

// 5
// 3 2 5 1 6