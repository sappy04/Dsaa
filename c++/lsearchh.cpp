#include<iostream>
using namespace std;
int lsear(int ar[],int n,int x)
{
 int temp=-1;
 for(int i=0;i<n;i++)
 {
    if(ar[i]==x)
    {
        cout<<"element found at position"<<i+1<<endl;
        temp=0;
    }
 }
 if(temp==-1)
 
    cout<<"match not found"<<endl;
    else
    cout<<"match found"<<endl;
 
}
int main()
{
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    
    int ma[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ma[i];
    }
    int x;
    cout << "Enter the element to be searched " << endl;
    cin >> x;
    lsear(ma,n,x);
    for (int i = 0; i < n; i++)
    {
        cout << ma[i] << " ";
    }
return 0;
}