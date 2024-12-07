#include <bits/stdc++.h>
using namespace std;
void sortkaro(int array[], int n)
{
    for (int i = 0; i < (n - 1); i++)
    {
        int mini_index = i; // store kar liya for comparison
        for (int j = i + 1; j < n; j++)//check kar raha in entire array chota se bhi chota element exist karta hai kya?
        {
            if (array[mini_index] > array[j])//agar i>j hai bhai j ko store kara
            {
                mini_index = j; // store kara liya bhai chota item ko
            }
        }
        swap(array[mini_index], array[i]);//chote ko bare se swap kiya
    }
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
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
    sortkaro(array, n);
    return 0;
}



// #include<iostream>
// using namespace std;
// void sorting(int array[],int n)
// {
//     for(int i=0;i<(n-1);i++)//universal fact after seeing the dry run
//     {
//         int mini=i;//stored for comparing the first element
//         for(int j=i+1;j<n;j++)
//         {
//             if(array[mini]>array[j])
//             {
//                 mini=j;
//             }
//         }
//         swap(array[mini],array[i]);
//     }
//     for(int i=0;i<n;i++)
//     {
//         cout<<array[i]<<" ";
//     }
// }
// int main()
// {
//     int n;
//     cin>>n;
//     int array[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>array[i];
//     }
//     sorting(array,n);
// return 0;
// }

