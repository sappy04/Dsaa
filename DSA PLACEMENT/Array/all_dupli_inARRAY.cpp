#include <iostream>
#include <algorithm>
using namespace std;
int dupli(int array[],int n)
{
    sort(array,array+n);
    bool hasdup=false;
    for(int i=0;i<=n;i++)
    {
        if(array[i]==array[i+1])
        {
            cout<<array[i]<<" ";
            // return array[i];
            hasdup=true;
        }
    }
    if(hasdup==false)
    {
        cout<<"No duplicate found"<<endl;
    }
    else
    {
        cout<<"Duplicate found"<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    dupli(array,n);
    return 0;
}