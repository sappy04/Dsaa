#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i = 0;
    int sum = 0;
    // while (i <= n)
    // {
    //     cout << i << endl;
    //     i++;
    // }

    // do{
    //     cout<<i<<endl;
    //     i++;
    // }while(i<=n);

    // for(int i=0;i<=n;i++)
    // {
    //     sum+=i;
    // }
    // cout<<"sum is: "<<sum<<endl;

    do
    {
        sum = sum + i;
        i++;
    } while (i <= n);
    cout << "the sum is: " << sum << endl;
    return 0;
}