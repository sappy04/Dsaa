#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the range: ";
    cin >> n;
    int a=0;
    int b=1;
    cout<<a<<" "<<b<<" ";
    for(int i=0;i<n;i++)
    {
        int c=a+b;//1
        cout<<" "<<c<<" ";
        a=b;
        b=c;
    }
    return 0;
}