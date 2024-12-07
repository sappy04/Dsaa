#include<iostream>
using namespace std;
void inssy(int a[],int n)
{
    int j=0;int key;
    for(int i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements" << endl;
    cin >> n;
    int myarr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> myarr[i];
    }
    inssy(myarr, n);
    cout << "after soorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << myarr[i] << " ";
    }
return 0;
}