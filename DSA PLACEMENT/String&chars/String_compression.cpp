#include <bits/stdc++.h>
using namespace std;
int compression(char chars[], int length)
{
    int i = 0;//to traverse original array
    int answerIndex = 0; //to traveerse compressed array // declaration over
    while (i < length)
    {
        int count = 0;//variable to count
        char currentchar = chars[i];//storing for check
        while (i < length && currentchar==chars[i])//genuinue simple check
        {
            i++;
            count++;
        }

        chars[answerIndex++]=currentchar;//counting and updation over
        if(count>1)
        {
            string cnt=to_string(count);
            for(int i=0;i<cnt.length();i++)//haha
            {
                chars[answerIndex++]=cnt[i];//updating number beside alphabet
            }
        }
    }
    return answerIndex;
}
int main()
{
    char chars[100];
    cin >> chars;//inputting char
    int length = strlen(chars);//original length
    int newlength = compression(chars, length);//length after compression

    cout << "[";
    for (int i = 0; i < newlength; i++)
    {
        cout << "'" << chars[i] << "'";//printing elements in epostrophy
        if (i < newlength - 1)
        {
            cout << ",";//seperating by comma
        }
    }
    cout << "]" << endl;
    return 0;
}

// string getCompressedString(string &input) {
//     // Write your code here.
//     int i = 0; // to traverse the input string
//     string result = ""; // this will store the compressed string
    
//     while (i < input.length()) {
//         int count = 1; // to count the repetitions of the current character
//         char currentChar = input[i]; // store the current character
        
//         // Check for the repetition of the current character
//         while (i + 1 < input.length() && input[i + 1] == currentChar) {
//             i++;
//             count++;
//         }
        
//         // Append the character to result
//         result += currentChar;
        
//         // If the character is repeated more than once, append the count as well
//         if (count > 1) {
//             result += to_string(count); // convert the count to a string and append it
//         }
        
//         i++; // move to the next character
//     }
    
//     return result;
// }