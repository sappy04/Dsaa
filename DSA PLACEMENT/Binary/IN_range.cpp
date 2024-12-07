#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;                  // i/p le liya
    string num = to_string(n); // for reversal of no
    bool neg = num[0] == '-';  // checked
    if (neg == '-')            // if yes then
    {
        num = num.substr(1); // removed -
    }
    reverse(num.begin(), num.end());
    string reversed;

    if (neg == '-')
    {
        reversed = num + '-';
    }
    else
    {
        reversed = num;
    }
    long long answer = stoll(reversed);
    if (answer < INT_MIN || answer > INT_MAX)
    {
        cout << "Out of range" << endl;
    }
    else
    {
        cout << answer << endl;
    }
    return 0;
}