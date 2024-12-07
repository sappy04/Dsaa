#include <bits/stdc++.h>
using namespace std;
void saydigit(int n, string array[])
{
    if (n == 0)
    {
        return;
    }
    int digit = n % 10;
    n = n / 10;
    saydigit(n,array);
    cout << array[digit] << " ";
}
int main()
{
    int n;
    cin >> n;
    string array[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    saydigit(n, array);
    return 0;
}