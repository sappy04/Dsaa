#include <iostream>
using namespace std;
int sum(int a, int b)
{
    int x = a;
    int y = b;
    return(x+y);
}
int sum(int a, int b, int c)
{
    int x = a;
    int y = b;
    int z = c;
    return(x*y*z);
}
double sum(double a, double b)
{
    int x = a;
    int y = b;
    return(x/y);
}
int main()
{
    cout << "the addition is: " << sum(10, 9) << endl;
    cout << "the product is: " << sum(10, 2, 3) << endl;
    cout << "the division is: " << sum(10.0, 5.0) << endl;
    return 0;
}