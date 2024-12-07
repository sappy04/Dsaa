#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < 31; i++)
    {
        if ((pow(2,i)) == n)
        {
            cout << i << endl;
            return true;
        }
    }
    cout<<n<<" not a power of 2"<<endl;
    return false;
    return 0;
}