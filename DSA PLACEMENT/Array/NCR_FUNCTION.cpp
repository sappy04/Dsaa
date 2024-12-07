#include <iostream>
using namespace std;
int factorial(int n)
{
    int answer=1;
    if(n==0||n==1)
    {
        return 1;
    }
    else
    {
        answer=n*factorial(n-1);
    }
    return answer;
}
int checkkar(int n,int r)
{
    int answer=(factorial(n))/(factorial(r)*factorial(n-r));
    return answer;
}
int main()
{
    int n;
    int r;
    cout << "Enter the n and r for ncr: ";
    cin >> n;
    cin >> r;
    cout<<"The ncr is : "<<checkkar(n, r)<<endl;
    return 0;
}