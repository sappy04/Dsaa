#include <bits/stdc++.h>
using namespace std;

bool searching(int array[], int start, int end, int target)
{
    if (start > end)
    {
        return false; // If start exceeds end, target is not found
    }

    int mid = start + (end - start) / 2; // Calculate mid

    if (array[mid] == target)
    {
        return true; // If mid element is the target, return true
    }
    else if (array[mid] > target)
    {
        return searching(array, start, mid - 1, target); // Search in the left half
    }
    else
    {
        return searching(array, mid + 1, end, target); // Search in the right half
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
    
    int target;
    cin >> target;
    
    // Pass correct arguments: n is not needed in the recursive function
    bool ans = searching(array, 0, n - 1, target);
    
    if (ans) // Use if (ans) to check if the element was found
    {
        cout << "element found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    
    return 0;
}
