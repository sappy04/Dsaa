#include <iostream>
using namespace std;
long long int sqrt(int n)
{
    int start = 0;
    int end = n;
    long long int ans = 1;
    while (start <= end)
    {
        long long int mid = start + ((end - start) / 2);
        if ((mid * mid) == n)
        {
            return mid;
        }
        else if ((mid * mid) > n)
        {
            end = mid - 1;
        }
        else if ((mid * mid) < n)
        {
            ans = mid;
            start = mid + 1;
        }
    }
    return ans;//as in non perfect square number it can be a possibilty
}
double moreprec(int prec,int n)
{
    long long int intpart=sqrt(n);
    double more_prec=intpart;
    double incr=0.1;
    for(int i=0;i<prec;i++)
    {
        while((more_prec*more_prec)<=n)
        {
            more_prec=more_prec+incr;
        }
        more_prec=more_prec-incr;;
        incr=incr/10;
    }
    return more_prec;
}
int main()
{
    int n;
    cin >> n;
    int prec;
    cin>>prec;
    double ans = moreprec(prec,n);
    cout << "Square root is: " << ans << endl;
    return 0;
}