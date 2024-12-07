#include <iostream>
using namespace std;
int main()
{
    char v = 'A';
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << v << " ";
            v++;
        }
        cout << endl;
    }
cout<<endl<<endl;
    for (int i = 1; i <= 4; i++)
    {
        char temp='A'+i-1;
        for (int j = 1; j <= i; j++)
        {
            cout << temp << " ";
            temp++;
        }
        cout << endl;
    }
cout<<endl<<endl;

    for (int i = 1; i <= 4; i++)
    {
        char temp='A'+4-i;
        for (int j = 1; j <= i; j++)
        {
            cout << temp << " ";
            temp++;
        }
        cout << endl;

    }
    return 0;
}