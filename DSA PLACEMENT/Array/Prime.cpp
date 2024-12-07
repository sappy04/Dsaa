#include <iostream>
using namespace std;
void isprime(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
        }
    }
    if (count == 2)
    {
        cout << "prime Number: "<<n << endl;
    }
    else
    {
        cout << "Not a prime Number: "<<n << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        isprime(i);
    }
    return 0;
}