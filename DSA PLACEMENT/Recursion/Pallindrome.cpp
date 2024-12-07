#include <bits/stdc++.h>
using namespace std;

bool bculta(string &str, int start, int end)
{
    if (start >= end)
    {
        return true; // Base case: If start meets or exceeds end, it's a palindrome
    }
    if (str[start] != str[end])
    {
        return false; // Characters at start and end don't match
    }

    return bculta(str, start + 1, end - 1); // Check the next pair of characters
}

int main()
{
    string str;
    getline(cin, str); // Input the entire string including spaces
    bool ans = bculta(str, 0, str.length() - 1);

    if (ans)
    {
        cout << "YES palindrome" << endl;
    }
    else
    {
        cout << "NO palindrome" << endl;
    }

    return 0;
}
