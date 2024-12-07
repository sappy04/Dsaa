/*code name pay experie company name*/
#include <iostream>
using namespace std;
class base
{
protected:
    double v;

public:
    double gv(double a)
    {
        v = a;
    }
    double sd()
    {
        cout << "the value of the variable is: " << v << endl;
    }
};
class deri : virtual public base
{
protected:
    double v1;

public:
    double gv1(double b)
    {
        v1 = b;
    }
    double sd1()
    {
        cout << "the value of the variable is: " << v1 << endl;
    }
};
class deri2 : virtual public base
{
protected:
    double v2;

public:
    double gv2(double c)
    {
        v2 = c;
    }
    double sd2()
    {
        cout << "the value of the variable is: " << v2 << endl;
    }
};
class master : public deri, public deri2
{
public:
double sum;
    double shd()
    {
        //cout<<"the value of var is: "<<deri::sd1()<<endl;
        //sum = deri2::sd2() + deri::sd1();
        sum=v2+v1;
        cout << "the value is" <<" " <<sum << endl;
    }
};
int main()
{
    master m;
    m.gv(5);
    m.sd();
    m.gv1(6);
    m.sd1();
    m.gv2(7);
    m.sd2();
    m.shd();
    return 0;
}