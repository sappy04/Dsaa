#include <bits/stdc++.h>
using namespace std;
void solve(stack<int> &s, int count, int size)
{
    if (count == (size / 2)) // agar mai middle mai pohuch gya...BASE CASE
    {
        s.pop(); // middle wala element ko delete kiya
        return;
    } // agar nahi hua then
    int numabove = s.top();    // abhi upar wale value ko store kar raha hoon
    s.pop();                   // hataya top value ko middle tak jana hai abhi
    solve(s, count + 1, size); // recursive call kiya
    s.push(numabove);          // upar k sare value stack mai daal diya
}
int main()
{
    int size;
    cin >> size;   // size input le liya
    stack<int> s;  // stack bana dala
    int count = 0; // to traverse kitna deep gaya hai
    int input;
    for (int i = 0; i < size; i++)
    {
        cin >> input;  // input liya
        s.push(input); // stack mai dala
    }
    solve(s, count, size);
    cout << "Stack after deleting the middle element (from top to bottom):\n";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}