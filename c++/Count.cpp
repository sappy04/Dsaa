#include<iostream>
using namespace std;
int count(int a[],int s,int r)
{
    int counta[r];
    int outputa[s];
    for(int i=0;i<r;i++)
    {
        counta[i]=0;
    }
    for(int i=0;i<s;i++)//countt the number of element in the input array
    {
        ++counta[a[i]];
    }
    for(int i=1;i<r;i++)
    {
        counta[i]=counta[i]+counta[i-1];
    }
    for(int i=0;i<s;i++)
    {
        outputa[--counta[a[i]]]=a[i];
    }
    for(int i=0;i<s;i++)
    {
        a[i]=outputa[i];
    }
}
int main()
{
    int r=1000;
    int s;
    cout << "Enter the number of elements" << endl;
    cin >> s;
    int myarr[s];
    for (int i = 0; i < s; i++)
    {
        cin >> myarr[i];
    }
    count(myarr,s,r);
    cout << "after sorting" << endl;
    for (int i = 0; i < s; i++)
    {
        cout << myarr[i] << " ";
    }    
return 0;
}
