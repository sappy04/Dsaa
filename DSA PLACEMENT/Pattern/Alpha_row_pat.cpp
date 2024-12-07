#include <iostream>
using namespace std;
int main()
{
   

    for (int i = 1; i <= 3; i++)
    {
        char let='A';
        for (int j = 1; j <= 3; j++)
        {
            cout << let << " ";
            let++;
        }
        cout << endl;
    }

    cout << endl;

    char count = 'A';
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cout << count << " ";
            count++;
        }
        cout << endl;
    }

    cout << endl
         << endl;

    for (int i = 1; i <= 3; i++)
    {
        char temp = 'A'+i-1;
        for (int j = 1; j <= 3; j++)
        {
            cout << temp << " ";
            temp++;
        }
        cout << endl;
    }

    cout << endl<< endl;

    for (int i = 1; i <= 3; i++)
    {
        char tempo='A'+i-1;
        for (int j = 1; j <= i; j++)
        {
            cout << tempo << " ";
        }
        cout << endl;
    }
cout<<endl<<endl;
    for (int i = 1; i <= 3; i++)
    {
        char let='A'+i-1;
        for (int j = 1; j <= 3; j++)
        {
            cout << let << " ";
        }
        cout << endl;
    }

    return 0;
}