#include<iostream>
using namespace std;
int main()
{
    for(int i=1;i<=4;i++)
    {
        //spaces
        int spaces=4-i;
        for(int j=1;j<=spaces;j++)
        {
            cout<<" ";
            
        }
        //2nd triangle
        for(int j=1;j<=i;j++)
        {
            cout<<j;
        }
        
        //3rd trianlgle
        for(int j=i-1;j>=1;j--)
        {
            cout<<j;
        }
        cout<<endl;
    }
return 0;
}