#include <iostream>
using namespace std;

void removeAdjacentDuplicates(char str[]) {
    // This array will store the result without adjacent duplicates
    char result[100];  
    int j = 0;  // Index for the result array

    for (int i = 0; str[i] != '\0'; i++) {
        // Check if the result is empty or if the last character in result is not the same as current character
        if (j == 0 || result[j - 1] != str[i]) {
            result[j] = str[i];  // Add current character to result
            j++;  // Move to next position in the result
        } else {
            j--;  // Remove the last character from the result
        }
    }

    result[j] = '\0';  // Null-terminate the result string

    // Print the final result
    cout << "String after removing adjacent duplicates: " << result << endl;
}

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);  // Read the input string
    removeAdjacentDuplicates(str);  // Call the function to remove adjacent duplicates
    return 0;
}
