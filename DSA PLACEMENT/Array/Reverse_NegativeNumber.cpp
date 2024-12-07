#include <iostream>
#include <climits>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s = to_string(n);
    bool neg = s[0] == '-';
    if (neg)
    {
        s = s.substr(1);
    }
    reverse(s.begin(), s.end());
    string answer = (neg ? "-" + s : s);

    cout << "before reversal: " << n << endl;
    cout << "after reversal: " << answer << endl;
    
    return 0;
}
