#include<bits/stdc++.h>
using namespace std;
void sortkaro(int array[],int n)
{
    for(int i=1;i<n;i++)//i ko 2nd position pe rakha
    {
        int key=array[i];//store kiya 
        int j; 
        for(j=i-1;j>=0;j--)//i ke peeche set kar diya
        {
            if(array[j]>key)
            {
                array[j+1]=array[j];//shifted and copied
            }
            else
            {
                break;
            }
        }
        array[j+1]=key;//j to 0 hogaya na abhi 1 kiya aur pehla value daal diya
    }
    for (int i = 0; i < n; i++)
    {
        
        cout<<array[i]<<" ";
    }
    
}
int main()
{
    int n;
    cin>>n;
    int array[100];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    sortkaro(array,n);
return 0;
}

// // #include <iostream>
// // using namespace std;
// // void sorting(int ar[], int n)
// // {
// //     for(int i = 1; i < n; i++)// Start from the second element
// //     {
// //         int key = ar[i];// Store the current element to be inserted
// //         int j = i - 1;
        
// //         // Shift elements of the sorted part that are greater than the key
// //         while(j >= 0 && ar[j] > key)
// //         {
// //             ar[j + 1] = ar[j];
// //             j--;
// //         }
// //         ar[j + 1] = key;  // Insert the stored key in the correct position
// //     }
    
// //     // Output the sorted array
// //     for(int i = 0; i < n; i++)
// //     {
// //         cout << ar[i] << " ";
// //     }
// // }
// // int main()
// // {
// //     int n;
// //     cin >> n;
// //     int array[n];
// //     for (int i = 0; i < n; i++)
// //     {
// //         cin >> array[i];
// //     }
// //     sorting(array, n);
// //     return 0;
// // }

// #include<iostream>
// using namespace std;
// void sort(int ar[],int n)
// {
//     int key,j;
//     for(int i = 1; i < n; i++)//1st key already sorted
//     {
//          key=ar[i];//store the key for positioning
//         for( j=i-1;j>=0;j--)//set at first(0 index) of the array
//         {
//             if(ar[j]>key)//i aur j ka comparision ...agar peeche wala ekement bara hua then
//             {
//                 ar[j+1]=ar[j];//shifted and copied the value in place of i...
//             }
//             else
//             {
//                 break;
//             }
//         }
//         ar[j+1]=key;//chota element ko 

//     }
//     for(int i=0;i<n;i++)
//     {
//         cout<<ar[i]<<" ";
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int array[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> array[i];
//     }
//     sort(array, n);
//     return 0;
// }