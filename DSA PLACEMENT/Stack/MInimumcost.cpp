#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum cost to balance the brackets
int findmincost(string input)
{
    if (input.length() % 2 == 1) // Odd length can't be balanced
    {
        return -1;
    }

    stack<char> s;

    // Process each character in the input string
    for (int i = 0; i < input.length(); i++)
    {
        char ch = input[i]; // Store current character

        if (ch == '{') // If it's an opening bracket, push to stack
        {
            s.push(ch);
        }
        else // Closed bracket
        {
            // If top is '{', we have a balanced part, so pop it
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
            {
                s.push(ch); // Push unbalanced '}' onto stack
            }
        }
    }

    // Stack now contains unbalanced brackets
    int a = 0, b = 0; // `a` for close brackets, `b` for open brackets count
    while (!s.empty())
    {
        if (s.top() == '{')
        {
            b++;
        }
        else
        {
            a++;
        }
        s.pop();
    }

    // Calculate the minimum cost to balance
    int ans = ((a + 1) / 2) + ((b + 1) / 2);
    return ans;
}

int main()
{
    string input;
    getline(cin, input);

    int result = findmincost(input); // Call function and store result

    if (result == -1)
    {
        cout << "Input length is odd, so it can't be balanced." << endl;
    }
    else
    {
        cout << "Minimum cost to balance brackets: " << result << endl;
    }

    return 0;
}
