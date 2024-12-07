#include <bits/stdc++.h>
using namespace std;
int main()
{
    // double m=5;
    // double *p=&m;
    // double temp=*p+1;
    // cout<<"copied pointer value: "<<temp<<endl;
    // cout<<"before p"<<p<<endl;
    // p=p+1;  //demo of incrementing a pointer by one place suppose m is at address at 100 by doing +1 we move to 104 address
    // cout<<"after p"<<p<<endl;

    // int arr[10]={2,3,4};
    // cout<<arr<<endl;
    // cout<<&arr<<endl;
    // cout<<*arr<<endl;
    // cout<<*(arr+1)<<endl;
    // cout<<*(arr)+1<<endl;//1st element +1
    // cout<<arr[2]<<endl;
    // cout<<*(arr)+2<<endl;

    // int a[10]={1,2,3,4,5};
    // cout<<"Address a is: "<<a<<endl;
    // int *ptr=&a[0];
    // cout<<"Address ptr is: "<<&ptr<<endl;

    // char temp='z';
    // char *ptr=&temp;
    // cout<<ptr<<endl;


    char a[6]="abcde";
    char *ptr=&a[0];
    cout<<ptr<<endl;
    return 0;
}