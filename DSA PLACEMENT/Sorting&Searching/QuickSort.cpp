#include <bits/stdc++.h>
using namespace std;

int partition(int array[], int start, int end)
{
    int pivot = array[start];

    int cnt = 0;
    for (int i = start + 1; i <= end; i++)  // <= end (not < end)
    {
        if (array[i] < pivot)  // count elements less than pivot
        {
            cnt++;
        }
    }
    
    int right_pivotindex = start + cnt;
    swap(array[right_pivotindex], array[start]);

    int i = start, j = end;
    while (i < right_pivotindex && j > right_pivotindex)
    {
        while (array[i] < pivot)  // find element greater than pivot on left
        {
            i++;
        }
        while (array[j] > pivot)  // find element smaller than pivot on right
        {
            j--;
        }
        if (i < right_pivotindex && j > right_pivotindex)
        {
            swap(array[i], array[j]);
            i++;
            j--;
        }
    }
    return right_pivotindex;
}

void quicksort(int array[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int index = partition(array, start, end);
    // Left part sort
    quicksort(array, start, index - 1);
    // Right part sort
    quicksort(array, index + 1, end);
}

int main()
{
    int n;
    cin >> n;
    int array[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    quicksort(array, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}
