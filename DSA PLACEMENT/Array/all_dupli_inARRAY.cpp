// #include <iostream>
// #include <algorithm>
// using namespace std;
// int dupli(int array[],int n)
// {
//     sort(array,array+n);
//     bool hasdup=false;
//     for(int i=0;i<=n;i++)
//     {
//         if(array[i]==array[i+1])
//         {
//             cout<<array[i]<<" ";
//             // return array[i];
//             hasdup=true;
//         }
//     }
//     if(hasdup==false)
//     {
//         cout<<"No duplicate found"<<endl;
//     }
//     else
//     {
//         cout<<"Duplicate found"<<endl;
//     }
// }
// int main()
// {
//     int n;
//     cin>>n;
//     int array[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>array[i];
//     }
//     dupli(array,n);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr) {
    int n = arr.size();
    
    int slow = 0, fast = 0;  // Initialize slow and fast pointers as indices

    // Step 1: Detect the cycle
    while (true) {
        slow = arr[slow];          // Move slow pointer one step (using values as indices)
        fast = arr[arr[fast]];     // Move fast pointer two steps (using values as indices)
        
        if (slow == fast) break;   // Cycle detected when slow and fast meet
    }

    // Step 2: Find the duplicate
    slow = 0;  // Reset slow to the start
    while (slow != fast) {
        slow = arr[slow];  // Move slow pointer one step
        fast = arr[fast];  // Move fast pointer one step
    }

    return slow;  // The duplicate number
}

int main() {
    vector<int> arr = {3, 1, 3, 4, 2};  // Input array
    cout << "Duplicate: " << findDuplicate(arr) << endl;
    return 0;
}
