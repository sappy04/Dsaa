#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    int maxy=ar[0];
    int miny=ar[0];
    for(int i=0;i<n;i++)
    {
        // if(ar[i]>max)
        // {
        //     max=ar[i];
        // }
        // if(ar[i]<min)
        // {
        //     min=ar[i];
        // }
        maxy=max(maxy,ar[i]);
        miny=min(miny,ar[i]);
    }
    cout<<"Maximum element in array is "<<maxy<<endl;
    cout<<"Minimum element in array is "<<miny<<endl;
return 0;
}

// #include <iostream>
// #include <climits>
// using namespace std;
// int getmax(int arr[], int size)
// {
//     int max = INT_MIN;
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] > max)
//         {
//             max = arr[i];
//         }
//     }
//     return max;
// }
// int getmin(int arr[], int size)
// {
//     int min = INT_MAX;
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] < min)
//         {
//             min = arr[i];
//         }
//     }
//     return min;
// }
// int main()
// {
//     int size;
//     cin >> size;
//     int arr[size];
//     for (int i = 0; i < size; i++)
//     {
//         cin >> arr[i];
//     }

//     int maxx = getmax(arr, size);
//     cout << "max value in the array is: " << maxx << endl;
//     int minx = getmin(arr, size);
//     cout << "min value in the array is: " << minx << endl;
//     return 0;
// }