#include <iostream>
using namespace std;

void solve(string digits, string output, int index, string ans[], int &ansIndex, string mapping[]) {
    // Base case: If index reaches the length of digits, we've formed a complete combination.
    if (index >= digits.length()) {
        ans[ansIndex++] = output;  //output mai saare char combinations stored hai,wo answer mai coppied ho ja rahe hai after complete traversal of digits
        return;//ansindex=0 hai aur ans k answerindex pe saare value store ho rahe from output one by one by answerindex++
    }//terminate program

    
    int number = digits[index] - '0';  //string mai liye hue number  ko int mai convert kiya '2'->2
    string value = mapping[number];  // usnumber k corresponding charachters ko store kar liya

    
    for (int i = 0; i < value.length(); i++) //particular digits k charachters series ko ek ek karke output mai add kiya hai
    {
        // Add the current character to output and proceed to the next digit
        solve(digits, output + value[i], index + 1, ans, ansIndex, mapping);
    }
}

int letterCombinations(string digits, string ans[]) //return the total size of combination
{
    // If the input is empty, return 0 (no combinations possible)
    if (digits.empty()) {
        return 0;
    }

    // Mapping digits to corresponding characters
    string mapping[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    
    string output = "";  // temporaray variable sent from here to store combinations in solve
    int ansIndex = 0;  // answered index answer mai kitne total combinations stored hue hai uska track rakhte hai,aur ans ko print karne mai madad karta hai

    // Call the solve function to generate all combinations
    solve(digits, output, 0, ans, ansIndex, mapping);//answered index k reference value pass kiya gaya hai to answerindex ka total count of answerindex yaha pe store ho jayega jo ki charachters ko print karne k kaam aayega

    return ansIndex;  // Return the total number of combinations.
}

int main() {
    string digits;
    getline(cin, digits);  // Take input digits from user
    string ans[100];  //saare valid answer store karne k liye digits k
    int size = letterCombinations(digits, ans);  // Get the total number of combinations

    // Print all the generated combinations
    for (int i = 0; i < size; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
