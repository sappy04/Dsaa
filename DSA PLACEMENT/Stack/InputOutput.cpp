#include <bits/stdc++.h>
using namespace std;

int main() {
    int size;
    cout << "Enter the number of elements you want in the stack: ";
    cin >> size;  // Take the size of the stack as input

    stack<int> s; // Create a stack of integers
    int input;

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> input;   // Input each element
        s.push(input);  // Push each element onto the stack
    }

    cout << "Stack elements (from top to bottom):\n";
    while (!s.empty()) {    // Print and pop elements from the stack until it's empty
        cout << s.top() << " ";  // Display the top element
        s.pop();                 // Remove the top element
    }
    cout << endl;

    return 0;
}
