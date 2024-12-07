#include <iostream>
#include <algorithm>
using namespace std;

void findequivalent(int arr[], int n, int sum)
{
    // Loop through the array
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) // Start j from i+1 to avoid repeating pairs
        {
            // Check if the sum of arr[i] and arr[j] equals the given sum
            if ((arr[i] + arr[j]) == sum)
            {
                // Print the pair
                cout << "Pair found: " << arr[i] << " + " << arr[j] << " = " << sum << endl;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n; // Input the size of the array
    int arr[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Input the array elements
    }

    int sum;
    cout << "Enter the sum to be checked: ";
    cin >> sum;

    sort(arr,arr+n);

    findequivalent(arr, n, sum); // Call the function to find pairs

    return 0;
}
