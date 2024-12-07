#include <iostream>
#include <bitset>
using namespace std;
bitset<32> twocomp(bitset<32> b)
{
    for (int i = 0; i < b.size(); i++)
    {
        b[i] = !b[i];
    }

    bool carry = 1;
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == 1 && carry == 1)
        {
            b[i] = 0; // 1 + 1 = 0 with a carry
        }
        else if (b[i] == 0 && carry == 1)
        {
            b[i] = 1;  // 0 + 1 = 1, no more carry needed
            carry = 0; // Stop the carry as we added 1
        }
        else
        {
            break;
        }
    }
    return b;
}
int main()
{
    int n;
    cin >> n;
    if (n >= 0)
    {
        bitset<32> binary(n);
        cout << "binary of the positive number is: " << binary << endl;
    }
    else
    {
        bitset<32> b(abs(n));
        cout << "positive binary equivalent of the negative number: " << b << endl;

        bitset<32> twocomps = twocomp(b);
        cout << "answer of -ve decimal in binary is: " << twocomps << endl;
    }
    return 0;
}