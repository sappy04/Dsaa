// #include <bits/stdc++.h>
// using namespace std;
// char *reversed(char name[])//if you need to remove this pointer then you need to remove the return also and call it in the pallindrome function...same code is pasted below.
// {
//     int length = strlen(name);
//     reverse(name, name + length);
//     return name;
// }
// void pallindrome(char name[])
// {
//     char original[100];
//     strcpy(original, name);
//     if (strcmp(reversed(name), original) == 0)
//     {
//         cout << "pallindrome" << endl;
//     }
//     else
//     {
//         cout << "not pallindrome" << endl;
//     }
// }
// int main()
// {
//     char name[100];
//     cin >> name;

//     pallindrome(name);
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// // Function that reverses the string in place without returning a pointer
// void reverseString(char name[]) {
//     int length = strlen(name);
//     reverse(name, name + length);  // Reverse the string in place
// }

// void palindrome(char name[]) {
//     char original[100];
//     strcpy(original, name);  // Store a copy of the original string
//     reverseString(name);     // Reverse the string in place

//     if (strcmp(name, original) == 0) {  // Compare the reversed string with the original
//         cout << "palindrome" << endl;
//     } else {
//         cout << "not palindrome" << endl;
//     }
// }

// int main() {
//     char name[100];
//     cin >> name;

//     palindrome(name);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

void palli(char name[]) {
    int start = 0;
    int len = strlen(name);
    int end = len - 1;
    
    while (start < end) {

        while (start < len && !isalnum(name[start])) {
            start++;
        }
        // Move end backward if not alphanumeric
        while (end >= 0 && !isalnum(name[end])) {
            end--;
        }


        // Convert both characters to lowercase before comparing
        if (tolower(name[start]) != tolower(name[end])) {
            cout << "not palindrome" << endl;
            return;  // Exit if a mismatch is found  //if i give break it will come out of the loop and print pallindrom of cout,so need to give return 0 only
        }
        start++;
        end--;
    }
    
    // If the loop completes without mismatches, it's a palindrome
    cout << "palindrome" << endl;
}

int main() {
    char name[100];
    cin >> name;
    palli(name);
    return 0;
}

