#include <bits/stdc++.h>
using namespace std;

bool checkkaro(string expression) {
    stack<char> s; // Stack create kiya for checking brackets
    for (int i = 0; i < expression.length(); i++) // har expression ko check kar raha
    {
        char ch = expression[i]; // store kar liya expression ko
        // agar opening brackets hai to dalo
        if (ch == '{' || ch == '[' || ch == '(') {
            s.push(ch); // stack mai bharo
        }
        // agar closing bracket hai
        else {
            // Agar stack khali nahi hai
            if (!s.empty()) {
                char top = s.top(); // match karne k liye upar wale element se
                // current charachter ko stack k top se compare kiya
                if ((ch == '}' && top == '{') || 
                    (ch == ']' && top == '[') || 
                    (ch == ')' && top == '(')) {
                    s.pop(); // agar closing bracket hai to close karo
                }
                else {
                    return false; // agar match nahi hua to false
                }
            }
            else {
                return false; // agar closing bracket hai lekin stack khali hai
            }
        }
    }
    // agar stack khali hai toh expression valid hai, nahi toh invalid
    return s.empty(); // true agar khali hai, false agar kuch rahe gaya
}

int main() {
    string expression;
    getline(cin, expression); // expression input leliya
    bool ans = checkkaro(expression); // function call
    if (ans) {
        cout << "valid parenthesis" << endl; // valid case
    }
    else {
        cout << "not valid parenthesis" << endl; // invalid case
    }
    return 0;
}
