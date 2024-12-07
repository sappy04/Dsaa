// #include <iostream>
// #include <algorithm>
// using namespace std;

// void sorty(int arr[],int n)
// {
//     sort(arr,arr+n);
//     for (int i = n-1; i >=0; i--)
//     {
//         cout <<(arr[i])<<" ";
//     }
// }

// int main()
// {
//     int n;
//     cout << "Enter the size of the array: ";
//     cin >> n; // Input the size of the array
//     int arr[n];
//     cout << "Enter the elements of the array: ";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i]; // Input the array elements
//     }
//     sorty(arr,n); // Sorting the array to make sure it's in order
//     return 0;
// }


#include <iostream>
using namespace std;

void sorty(int arr[], int n)
{
    int i = 0, j = n - 1;

    // Two-pointer approach to sort 0s and 1s
    while (i < j)
    {
        // Move i forward if arr[i] is already 0
        if (arr[i] == 0)
        {
            i++;
        }
        // Move j backward if arr[j] is already 1
        else if (arr[j] == 1)
        {
            j--;
        }
        // If arr[i] is 1 and arr[j] is 0, swap them
        else if (arr[i] == 1 && arr[j] == 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        else{
            break;
        }
    }

    // Print the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n; // Input the size of the array

    int arr[n];
    cout << "Enter the elements of the array (0s and 1s only): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Input the array elements (should be 0s and 1s)
    }

    sorty(arr, n); // Call the sorting function

    return 0;
}
