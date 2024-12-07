#include <bits/stdc++.h>
using namespace std;

void firstNegativeInWindow(int arr[], int n, int k)
{
    queue<int> negatives; // Queue to store indices of negative numbers in the entire array

    // Process the first window
    for (int i = 0; i < k; i++)//pehla window check kar rahe hai
    {
        if (arr[i] < 0)//pehla window mai jitna negative mil gaya sab
        {
            negatives.push(i);//queue mai push kar de index number jaha jaha array mai negative hai
        }
    }

    
    for (int i = k; i < n; i++)//full rest of the range
    {

        if (!negatives.empty())//queue khali nahi hai to print karo yaar
        {
            cout << arr[negatives.front()] << " ";//yaha pe pehla element print kar de jo ki confirm 1st negative number hai window ka
        }
        else
        {
            cout << "0 "; // No negative number in the previous window
        }

        // Remove the elements that are out of this window
        while (!negatives.empty() && negatives.front() <= i - k)//window slide hua hai aur negative queue ka 2end element ban jata hai pehla element
        {
            negatives.pop();//pehle wala front ko hataya...new front ban gya hai
        }

        
        if (arr[i] < 0)
        {
            negatives.push(i);//aikhane que ta update hoche from array index jdi element negative hoy
        }
    }

    // Print the first negative number for the last window
    if (!negatives.empty())
    {
        cout << arr[negatives.front()] << " ";
    }
    else
    {
        cout << "0 ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // Window size

    cout << "First negative integer in every window of size " << k << ": ";
    firstNegativeInWindow(arr, n, k);

    return 0;
}
