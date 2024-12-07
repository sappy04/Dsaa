#include <iostream>
using namespace std;
class Rec // base class
{
public:
    float l, b;
    float gd(); // get data
    float d();  // display data
};
class Arec : public Rec // derived class inheriting base class
{
public:
    float a;
    float pd(); // process data
};
float Rec::gd() // defining the func gd of class rec
{
    cout << "Enter the length and breath " << endl;
    cin >> l >> b;
}
float Rec::d() // defining the func d of class rec
{
    cout << "The length is: \n"
         << l << "\nThe breath is: \n"
         << b << endl;
};
float Arec::pd() // defining the func pd of class Arec
{
    float a;
    a = l * b;
    cout << "The area is: " << a << endl;
};
int main()
{
    Arec c;
    c.gd();
    c.d();
    c.pd();
    return 0;
}