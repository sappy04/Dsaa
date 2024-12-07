#include <bits/stdc++.h>
using namespace std;
void ultakaro(string &array, int start, int end)
{
    if (start > end)
    {
        return;
    }

    swap(array[start++], array[end--]);
    ultakaro(array,start,end);
}
int main()
{
    string array;
    getline(cin, array);
    ultakaro(array,0,array.length()-1);
    cout<<array<<endl;
    return 0;
}