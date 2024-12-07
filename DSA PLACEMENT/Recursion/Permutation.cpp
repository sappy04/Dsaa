#include <bits/stdc++.h>
using namespace std;
 // for swap

// Function to generate permutations recursively
void solve(int nums[], int n, int index) {
    // Base case: If index reaches the size of nums, we've formed a complete permutation
    if (index >= n) {
        
        for (int i = 0; i < n; i++) {
            cout << nums[i] << " ";//index crosssed so saare permu print kardo jo nums k andar hai
        }
        cout << "\n";
        return;//base case mai hi answer print ho jayega
    }

    
    for (int j = index; j < n; j++) //0 to size of the numberi.e kitna number liye ho tak jayega
    {
        // Swap elements at index 'index' and 'j'
        swap(nums[index], nums[j]);//self swap

        solve(nums, n, index + 1);//num aur size wahi raahega lekin index+1 ho jayega for number to reach the next number(by index)
        
        swap(nums[index], nums[j]);//restores emptyness to store values for next stage
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int nums[1000];
    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Generate all permutations
    cout << "All permutations:\n";
    solve(nums, n, 0);

    return 0;
}
