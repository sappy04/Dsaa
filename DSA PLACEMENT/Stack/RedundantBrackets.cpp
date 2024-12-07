#include <bits/stdc++.h>
using namespace std;

// Function to check redundant brackets
bool redundant(string input)
{
    stack<char> s; // stack create kara

    for (int i = 0; i < input.length(); i++)
    {
        char ch = input[i]; // character ko store kara

        // Agar '(' ya operator hai, toh stack mein push karo
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            s.push(ch);
        }
        else
        {
            // Agar closing bracket ')' hai
            if (ch == ')')
            {
                bool isredundant = true;

                // Top par '(' tak check karo
                while (s.top() != '(') // agar  top par '(' matlab redundant matlab beech mai kuch nahi hai

                {
                    char top = s.top(); // so top ko uthao aur bc check kardo

                    // Agar operator mila, toh redundant nahi hai
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isredundant = false;
                    }
                    s.pop(); // operator delete hota hai
                }

                s.pop(); // opening bracket delete ho rahi hai

                // Agar redundant hai toh true return karo
                if (isredundant)
                {
                    return true;
                }
            }
        }
    }

    // Agar koi redundant brackets nahi mile toh false return karo
    return false;
}

int main()
{
    string input;
    getline(cin, input); // expression input leliya

    if (redundant(input))
    {
        cout << "Redundant brackets found." << endl;
    }
    else
    {
        cout << "No redundant brackets." << endl;
    }
    return 0;
}
