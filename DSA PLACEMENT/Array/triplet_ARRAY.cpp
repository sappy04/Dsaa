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
            for (int k = i + 2; k < n; k++) // Start k from j+1 to ensure unique elements
            {
                // Check if the sum of arr[i], arr[j], and arr[k] equals the given sum
                if ((arr[i] + arr[j] + arr[k]) == sum)
                {
                    // Print the triplet
                    cout << "Triplet found: " << arr[i] << " + " << arr[j] << " + " << arr[k] << " = " << sum << endl;
                }
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

    sort(arr, arr + n); // Sorting the array to make sure it's in order

    findequivalent(arr, n, sum); // Call the function to find the triplets

    return 0;
}
