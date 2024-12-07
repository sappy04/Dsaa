#include <iostream>
#include <algorithm>
using namespace std;
void merge(int ar[], int ar2[], int n, int n1)
{
    int size = n + n1;
    int array[size];
    for (int i = 0; i < n; i++)
    {
        array[i] = ar[i];
    }
    for (int i = 0; i < n1; i++)
    {
        array[n + i] = ar2[i];
    }
    sort(array, array + size);
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}
int main()
{
    int n, n1;
    cin >> n >> n1;
    int ar[n], ar2[n1];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    for (int i = 0; i < n1; i++)
    {
        cin >> ar2[i];
    }
    merge(ar, ar2, n, n1);
    return 0;
}