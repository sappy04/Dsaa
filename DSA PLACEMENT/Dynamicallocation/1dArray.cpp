#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size; // Input size of the 1D array

    // Create a 1D dynamic array
    int *arr = new int[size];

    // Input values into the 1D array
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // Output the array values
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Free the allocated memory
    delete[] arr;

    return 0;
}
