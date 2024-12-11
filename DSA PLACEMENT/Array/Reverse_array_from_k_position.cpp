#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int m) {
    int start = m + 1;
    int end = arr.size() - 1;

    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n, m; // Array size and index 'm'
        cin >> n >> m;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        reverseArray(arr, m);

        // Print the modified array
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
