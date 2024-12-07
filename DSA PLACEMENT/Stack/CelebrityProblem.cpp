#include <bits/stdc++.h>
using namespace std;

bool knows(int arr[][100], int a, int b, int n)//persons sequensely hi marked honge from 0.
{
    if (arr[a][b] == 1)//check kar raha matrix mai ki kya mera a th elemnt bth element ko janta hai? agar haa to 1 ayega ans
    {
        return true;
    }
    else
    {
        return false;//nahi janta to false ayega
    }

}

int main()
{
    int n; // input the size of the matrix
    cin >> n;
    int arr[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    stack<int> s;               // stack banaya
    for (int i = 0; i < n; i++) // step 1
    {
        int element;
        cin >> element;
        s.push(element); // stack mai saare values daal diya
    }

    while (s.size() > 1) // jab tak stack mai 1 element nahi bach jata check karte raho
    {
        // 2 element pop kar diya
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (knows(arr, a, b, n))//agar array mai a b ko janta hai to a to paka celbrity nahi hai to b ko push karo
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }

    // abhi stack mai single element hai
    int candidate = s.top();

    // to verify by row and col check
    // row check
    bool rowcheck = false;
    int zerocount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[candidate][i] == 0)
        {
            zerocount++; // zero count kar liya
        }
    }
    if (zerocount == n) // check kar liya bhai sare zero hai ki nahi
    {
        rowcheck = true;
    }

    bool colcheck = false;
    int onecount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][candidate] == 1)
        {
            onecount++; // one count kar liya
        }
    }
    if (onecount == (n - 1)) // check kar liya bhai sare one hai ki nahi
    {
        colcheck = true;
    }

    // final check
    if (rowcheck && colcheck)
    {
        cout << "Celebrity ID: " << candidate << endl;
    }
    else
    {
        cout << "No Celebrity Found" << endl;
    }

    return 0;
}
