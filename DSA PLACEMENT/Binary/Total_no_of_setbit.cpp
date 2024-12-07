#include <iostream>
#include <bitset>
using namespace std;
int countbit(int a, int b)
{
    bitset<32> bin1(a);
    bitset<32> bin2(b);
    string st1 = bin1.to_string();
    string st2 = bin2.to_string();
    string st3 = st1 + st2;
    int count = 0;
    for (int i = 0; i < st3.length(); i++)
    {
        if (st3[i] == '1')
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int a, b;
    cin >> a >> b;
    int result = countbit(a, b);
    cout << "The total count of setbit is in a and b: " << result << endl;
    return 0;
}