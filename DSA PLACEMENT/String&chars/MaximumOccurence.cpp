#include <bits/stdc++.h>
using namespace std;

void maxOccurrence(string str) {
    int count[256] = {0};  // Array to store the count of each character (ASCII range)
    int maxCount = 0;      // Variable to track the maximum count
    char maxChar;          // Variable to track the character with the maximum count
    bool allEqual = true;  // Flag to check if all counted characters are equal

    // Count occurrences of each character
    for (int i = 0; i < str.length(); i++) {
        count[str[i]]++;  // Increment the count for the character at index i
    }

    // Find the character with the maximum occurrence
    for (int i = 0; i < 256; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i]; // Update the maximum count
            maxChar = i;          // Update the character with the max count
            allEqual = false;     // If we found a new max, not all are equal
        } else if (count[i] == maxCount && count[i] > 0) {
            allEqual = true; // Found another character with the same max count
        }
    }

    // Output the result
    if (allEqual && maxCount > 0) {
        cout << "All characters have equal occurrence. Returning count: 0" << endl;
    } else if (maxCount > 0) {  // Ensure there was at least one character counted
        cout << "Character with maximum occurrence: '" << maxChar << "' (Count: " << maxCount << ")" << endl;
    } else {
        cout << "No characters found." << endl;  // In case the string was empty
    }
}

int main() {
    string str;
    cout << "Enter a string: ";  // Prompt the user for input
    getline(cin, str);           // Read the full line including spaces
    maxOccurrence(str);          // Call the function to find and print the maximum occurrence
    return 0;                    // Return 0 to indicate successful execution
}

