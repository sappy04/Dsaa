#include <iostream>
#include <algorithm>
using namespace std;

int firstOcc(int ar[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    int mid = start + ((end - start) / 2); // for optimization
    int ans = -1;                          // to store the index.
    while (start <= end)
    {
        if (ar[mid] == key)
        {
            ans = mid;     // Store the position of the element
            end = mid - 1; // Move to the left part to find the first occurrence
        }
        else if (ar[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + ((end - start) / 2);
    }
    return ans;
}

int lastOcc(int ar[], int n, int key) // REMEMBER THAT ARRAY IS SORTED
{
    int start = 0;
    int end = n - 1;
    int mid = start + ((end - start) / 2); // for optimization
    int ans = -1;                          // to store the index when key is found
    while (start <= end)
    {
        if (ar[mid] == key)
        {
            ans = mid;
            start = mid + 1; // Move to the right part for the last occurrence
        }
        else if (ar[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + ((end - start) / 2);
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    int ar[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    
    sort(ar, ar + n); // Sorting the array

    int key;
    cout << "Enter the key to be searched: ";
    cin >> key;

    // Capture the first and last occurrence
    int first = firstOcc(ar, n, key);
    int last = lastOcc(ar, n, key);

    // If the element is not found, first and last will be -1
    if (first == -1 || last == -1)
    {
        cout << "Element is not present in the array." << endl;
    }
    else
    {
        // Print first and last occurrence
        cout << "First occurrence of " << key << " is at index: " << first << endl;
        cout << "Last occurrence of " << key << " is at index: " << last << endl;

        // Calculate and print the total number of occurrences
        int total_occ = (last - first) + 1;//formulaaa
        cout << "Total number of occurrences: " << total_occ << endl;
    }

    return 0;
}
