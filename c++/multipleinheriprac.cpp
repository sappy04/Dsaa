#include <iostream>
using namespace std;
class asq
{
public:
    double l;
    double sqa;
    double sq(double r)
    {
        l = r;
        sqa = (l * l * l);
        cout << "the area of the square is: " << sqa << endl;
    }
};
class arec
{
public:
    double l, b;
    double recar;
    double reca(double a, double c)
    {
        l = a;
        b = c;
        recar = (l * b);
        cout << "the area of the rectangle is: " << recar << endl;
    }
};
class sum : public arec, public asq
{
public:
    double add;
    double sumu()
    {
     add = sqa + recar;
     cout<<"the sum is: "<<add<<endl;
    }
};
int main()
{
    sum s;
    s.sq(5);
    s.reca(4, 3);
    s.sumu();
    return 0;
}