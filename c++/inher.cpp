#include <iostream>
using namespace std;
class Base // created base class
{
public: // kept everything public
    int d1, d2;
    void sd();
    void gd();
};
class Derived : public Base // inheriting base class
{
public:
    int d3;
    void pd();
};
void Base::sd() // modifing base class's sd
{
    d1 = 10;
    d2 = 20;
}
void Base::gd() // modifing base class's gd
{
    cout << "1st data is: " << d1 << endl;
    cout << "2nd data is: " << d2 << endl;
}
void Derived::pd()
{
    d3 = d1 + d2;
    cout << "The sum is: " << d3 << endl;
}
int main()
{
    Derived d;
    d.sd();
    d.gd();
    d.pd();
    return 0;
}