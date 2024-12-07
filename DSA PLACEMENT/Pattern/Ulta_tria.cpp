#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 4; i++)
    {
        // Print spaces
        for (int j = 1; j <= 4 - i; j++)
        {
            cout << " ";
        }
        // Print stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl; // Move to the next line after each row
    }
    cout << endl
         << endl;

    for (int i = 4; i >= 1; i--)
    {
        // Print stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl; // Move to the next line after each row
    }
    cout << endl
         << endl;

    for (int i = 4; i >= 1; i--)
    {
        // Print spaces
        for (int j = 1; j <= 4 - i; j++)
        {
            cout << " ";
        }
        // Print stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl; // Move to the next line after each row
    }

    cout << endl
         << endl;

    int temp = 1;
    for (int i = 4; i >= 1; i--)
    {
        // Print spaces
        for (int j = 1; j <= 4 - i; j++)
        {
            cout << " ";
        }
        // Print stars
        for (int j = 1; j <= i; j++)
        {
            cout << temp;
        }
        temp++;

        cout << endl; // Move to the next line after each row
    }

    cout << endl
         << endl;

    for (int i = 4; i >= 1; i--)
    {
        // Print spaces
        for (int j = 1; j <= 4 - i; j++)
        {
            cout << " ";
        }
        // Print numbers
        int tempy = 5 - i; // Initialize tempy based on the row
        for (int j = 1; j <= i; j++)
        {
            cout << tempy;
            tempy++;
        }
        cout << endl; // Move to the next line after each row
    }



    cout << endl
         << endl;

    for (int i = 1; i <= 4; i++)
    {
        // Print spaces
        for (int j = 1; j <= 4 - i; j++)
        {
            cout << " ";
        }
        // Print stars
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl; // Move to the next line after each row
    }



    cout << endl
         << endl;
int count=1;
    for (int i = 1; i <= 4; i++)
    {
        // Print spaces
        for (int j = 1; j <= 4 - i; j++)
        {
            cout << " ";
        }
        // Print stars
        for (int j = 1; j <= i; j++)
        {
            cout << count;
            count++;
        }
        cout << endl; // Move to the next line after each row
    }
    return 0;
}
