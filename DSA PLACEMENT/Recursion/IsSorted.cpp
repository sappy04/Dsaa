#include <bits/stdc++.h>
using namespace std;
bool issorted(int array[],int n)
{
    if(n==0||n==1)
    {
        return true;
    }
   
        if(array[0]>array[1])
        {
            return false;
        }
        else
        {
            bool remainingPart=issorted(array+1,n-1);
            return remainingPart;
        }
   
}
int main()
{
    int n;
    cin>>n;
    int array[100];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    int ans=issorted(array,n);
    if(ans==1)
    {
        cout<<"array sorted"<<endl; 
    }
    else
    {
        cout<<"array not sorted"<<endl;
    }
    return 0;
}