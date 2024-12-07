#include<iostream>
using namespace std;
int main()
{
    int count=1;
    for(int i=1;i<=4;i++)
    {
        int temp =i;
        for(int j=1;j<=i;j++)
        {
            cout<<temp<<" ";
            temp++;
        }
        cout<<endl;
    }
return 0;
}

/* #include<iostream>
using namespace std;
int main()
{
    int count=1;
    for(int i=1;i<=4;i++)
    {
        //int temp =i;
        for(int j=1;j<=i;j++)
        {
            cout<<i-j+1<<" ";
            //temp--;
        }
        cout<<endl;
    }
return 0;
}
*/