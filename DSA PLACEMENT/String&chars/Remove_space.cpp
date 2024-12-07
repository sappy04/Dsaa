#include <bits/stdc++.h>
using namespace std;

void removespace(string str) {
    string result = "";  // To store the new string with replaced characters
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {   // Use single quotes to compare with a character
            result += "@40";   // Replace space with '@40'
        } else {
            result += str[i];  // Add the character as it is if it's not a space
        }
    }
    cout << result << endl;    // Output the modified string
}

int main() {
    string str;
    getline(cin, str);         // Read the input string with spaces
    removespace(str);          // Call the function to remove spaces
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// void removespace(string str) {
//     string result = "";  // New string to store the result

//     // Iterate through the input string
//     for (int i = 0; i < str.length(); i++) {
//         if (str[i] != ' ') {   // If the current character is not a space
//             result += str[i];  // Add it to the result string
//         }
//     }

//     cout << result << endl;    // Output the result string without spaces
// }

// int main() {
//     string str;
//     getline(cin, str);         // Read the input string including spaces
//     removespace(str);          // Call the function to remove spaces
//     return 0;
// }
