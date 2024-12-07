#include <iostream>
#include <cstring> // For strlen
#include <string>  // For std::string

using namespace std;

// Function to print all substrings of the given input string
void printSubstrings(char input[]) {
    int n = strlen(input);  // Get the length of the string

    // Outer loop to pick the starting index of the substring
    for (int i = 0; i < n; i++) {
        // Inner loop to pick the ending index of the substring
        for (int j = i; j < n; j++) {
            // Print the substring using the string constructor
            cout << string(input + i, input + j + 1) << endl;
        }
    }
}

int main() {
    char input[100]; // Array to store the input string (size can be adjusted)
    
    // Prompt user for input
    cout << "Enter a string: ";
    cin >> input;

    // Call the function to print all substrings
    cout << "\nSubstrings are:\n";
    printSubstrings(input);

    return 0;
}
