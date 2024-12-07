#include<iostream>
using namespace std;
bool issoln(int ar[],int n,int m,int mid)
{
    int student=1;
    int pagesum=0;
    for(int i=0;i<n;i++)
    {
        if(pagesum+ar[i]<=mid)
        {
            pagesum+=ar[i];
        }
        else
        {
            student++;
            if(student>m)
            {
                return false;
            }
            pagesum=ar[i];
        }
    }
    return true;
}
int allocate(int ar[],int n,int m)
{
    int start=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=ar[i];
    }
    int end=sum;
    int ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(issoln(ar,n,m,mid))
        {
            ans=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    int m;
    cin>>m;
    int ans=allocate(ar,n,m);
    cout<<ans<<endl;
return 0;
}
/*
4
10 20 30 40
2 
*/