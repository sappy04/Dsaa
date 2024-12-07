#include <bits/stdc++.h>
using namespace std;
void bubblesort(int array[], int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (array[i] > array[i + 1])
            swap(array[i], array[i + 1]);
    }
    bubblesort(array, n - 1);
}
int main()
{
    int n;
    cin >> n;
    int array[100];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i]; // array
    }
    bubblesort(array, n);
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}