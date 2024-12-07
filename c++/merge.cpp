// #include<iostream>
// using namespace std;
// int merge(int ar[],int l,int m,int r)
// {
//     int i=l;
//     int j=(m)/2;
//     int k=r;
//     int temp[5];
//     while(i<=m && j<=r)
//     {
//         if(ar[i]<=ar[j])
//         {
//             temp[i]=ar[i];
//             i++;
//             k++;
//         }
//         else
//         {
//             temp[i]=ar[j];
//             j++;
//             k++;
//         }
//     }
//     while(i<=m)
//     {
//       temp[i]=ar[i];
//             i++;
//             k++;
//     }
//     while(j<=r)
//     {
//       temp[i]=ar[j];
//             j++;
//             k++;
//     }
//     for(int p=l;i<=r;i++)
//     {
//         ar[p]=temp[p];
//     }
// }
// int mergesort(int ar[],int l,int r)
// {
//     if(l<r)
//     {
//         int m=(l+r)/2;
//         mergesort(ar,l,m);
//         mergesort(ar,(m+1),r);
//         merge(ar,l,m,r);
//     }
// }
// int main()
// {
//     int n;
//     int mar[n];
//     for(int i=0;i<n;i++)
//     {
//     cin>>mar[i];
//     }
//     mergesort(mar,0,(n-1));
//     for(int i=0;i<n;i++)
//     {
//     cout<<mar[i]<<" ";
//     }
//     return 0;
// }

#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r, int size)
{
    int i = l;
    int j = m + 1;
    int k = l;

    /* create temp array */
    int temp[size];

    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    /* Copy the remaining elements of first half, if there are any */
    while (i <= m)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of second half, if there are any */
    while (j <= r)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    /* Copy the temp array to original array */
    for (int p = l; p <= r; p++)
    {
        arr[p] = temp[p];
    }
}

/* l is for left index and r is
right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r, int size)
{
    if (l < r)
    {
        // find midpoint
        int m = (l + r) / 2;

        /* recurcive mergesort first
  and second halves */
        mergeSort(arr, l, m, size);
        mergeSort(arr, m + 1, r, size);

        // merge
        merge(arr, l, m, r, size);
    }
}

int main()
{
    cout << "Enter size of array: " << endl;
    int size;
    cin >> size;
    int myarray[size];

    cout << "Enter " << size << " integers in any order: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> myarray[i];
    }
    cout << "Before Sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myarray[i] << " ";
    }
    cout << endl;
    mergeSort(myarray, 0, (size - 1), size); // mergesort(arr,left,right) called

    cout << "After Sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myarray[i] << " ";
    }

    return 0;
}