#include <bits/stdc++.h>
using namespace std;
int main()
{
    string input;
    getline(cin, input); //

    stack<char> s; // stack create kara
    for (int i = 0; i < input.length(); i++)
    {
        char ch = input[i]; // charachter ko store kara
        s.push(ch);         // daal diya
    }
    string ans = "";
    while (!s.empty()) // jab tak stack khali nahi hai
    {
        char ch = s.top(); // top element ko store karega
        ans = ans + ch;
        s.pop();
    }
    cout << "reversed string is: " << ans << endl;
    return 0;
}