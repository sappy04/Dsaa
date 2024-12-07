#include <bits/stdc++.h>
using namespace std;
void merge(int array[], int start, int mid, int end)
{
    int len1 = mid - start + 1;     // len 1
    int len2 = end - (mid + 1) + 1; // len2

    int *leftside = new int[len1]; // 2 side ka array create kar diya
    int *rightside = new int[len2];

    // original to modified mai copy
    for (int i = 0; i < len1; i++)
    {
        leftside[i] = array[start + i];
    }
    for (int j = 0; j < len2; j++)
    {
        rightside[j] = array[mid + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = start; // sorting
    while (i < len1 && j < len2)
    {
        if (leftside[i] <= rightside[j])
        {
            array[k++] = leftside[i++];
        }
        else
        {
            array[k++] = rightside[j++];
        }
    }
    while (i < len1)
    {
        array[k++] = leftside[i++];
    }
    while (j < len2)
    {
        array[k++] = rightside[j++];
    }
    delete[] leftside;
    delete[] rightside;
}
void mergesort(int array[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergesort(array, start, mid);
        mergesort(array, (mid + 1), end);
        merge(array, start, mid, end);
    }
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
    mergesort(array, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}