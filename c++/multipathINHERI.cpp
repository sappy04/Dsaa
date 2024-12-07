#include <iostream>
using namespace std;
class person//takes code and name
{
    // protected:

public:
    int code;
    char name[100];
    void gd()
    {
        cout << "Enter the code of the person:" << endl;
        cin >> code;
        cout << "Enter the Name of the person:" << endl;
        cin >> name;
    }
    void dis()
    {
        cout << "The code of the person is" << code << endl;
        cout << "The name of the person is" << name << endl;
    }
};
class account : virtual public person//takes pay
{
    // protected:

public:
    double pay;
    void inp()
    {
        cout << "Enter the pay of the person:" << endl;
        cin >> pay;
    }
    void displ()
    {
        cout << "The pay of the person is" << pay << endl;
    }
};
class admin : virtual public person//takes experience
{
    // protected:

public:
    float exp;
    void inpu()
    {
        cout << "Enter the experience of the person:" << endl;
        cin >> exp;
    }
    void disp()
    {
        cout << "The experience of the person is" << exp << endl;
    }
};
class master : public admin, public account//takes comapny name
{
    // protected:

public:
    char namee[100];
    void inpt()
    {
        cout << "Enter the company name of the person:" << endl;
        cin >> namee;
    }
    void show()
    {
        cout << "The company name of the person is" << namee << endl;
    }
};
int main()
{
    master m;
    m.gd();
    m.inp();
    m.inpu();
    m.inpt();
    m.dis();
    m.displ();
    m.disp();
    m.show();
    return 0;
}