#include <bits/stdc++.h>
using namespace std;
void merge(int array[], int start, int mid, int end)
{
    // step1 temp left array ka size lo
    int len1 = mid - start + 1;
    int len2 = end - mid;
    // temp array banao left and right ka
    int *left = new int[len1]; // array declare kiya
    int *right = new int[len2];

    for (int i = 0; i < len1; i++) // temp array mai mid tak ka value bharo
    {
        left[i] = array[start + i]; // value daalo yaar array mai
    }
    for (int i = 0; i < len2; i++) // temp array mai mid k value se end tak ka value bharo
    {                   
        right[i] = array[mid + 1 + i];
    }

    // merge karo
    int i = 0, j = 0, k = start;
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j]) //
        {
            array[k++] = left[i++]; // chote values ko array mai daaalo
        }
        else
        {
            array[k++] = right[j++]; // bade values ko array mai daalo
        }
    }
    while (i < len1) // extra left out
    {
        array[k++] = left[i++]; // chote values ko array mai daaalo
    }
    while (j < len2)
    {
        array[k++] = right[j++]; // bade values ko array mai daalo
    }

    delete[] left;
    delete[] right;
}
void mergesort(int array[], int start, int end) //merge sort ka core logic
{
    if (start >= end) // basde case to stop
    {
        return;
    }
    int mid = (start + (end-start)) / 2;
    mergesort(array, start, mid);   // leftpart
    mergesort(array, mid + 1, end); // rightpart
    merge(array, start, mid, end);  // merge two sorted array
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
    mergesort(array, 0, n - 1);
    cout << "sorted array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}

