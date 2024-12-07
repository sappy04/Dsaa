#include<iostream>
using namespace std;
int main()
{
    // for(int i=1;i<=3;i++)
    // {
    //     for(int j=1;j<=3;j++)
    //     {
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    // }
    int i=1;
    while(i<=3)
    {
        int j=1;
        while(j<=3)
        {
            cout<<i<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
return 0;
}