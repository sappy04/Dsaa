#include <iostream>
using namespace std;

void sort012(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;

    // Process the array using three pointers
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            // Swap arr[low] and arr[mid] and increment low and mid
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            // Move mid forward
            mid++;
        }
        else if (arr[mid] == 2)
        {
            // Swap arr[mid] and arr[high] and decrement high
            swap(arr[mid], arr[high]);
            high--;
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
    cout << "Enter the elements of the array (0s, 1s, and 2s only): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Input the array elements (should be 0s, 1s, and 2s)
    }

    sort012(arr, n); // Call the sorting function

    return 0;
}
