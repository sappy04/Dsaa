#include <iostream>
using namespace std;

void rotate(int array[], int n, int index) {
    int temp[n]; // Create a temporary array

    // Copy elements to the temporary array in rotated order
    for (int i = 0; i < n; i++) {
        temp[(i + index) % n] = array[i]; // Use '=' for assignment       //formulaa
    }

    // Copy back to the original array
    for (int i = 0; i < n; i++) {
        array[i] = temp[i];
    }

    // Print the rotated array
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
}

int main() {
    int n;
    cin >> n;
    int index;
    cin >> index;
    int array[n]; // Note: Using Variable Length Array, consider using dynamic memory in practice
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    rotate(array, n, index);
    return 0;
}
