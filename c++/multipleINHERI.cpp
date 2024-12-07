#include <iostream>
using namespace std;//NOTE: in multiple interitance straight double inheritance in last class..no in between inheritance
class Arec
{
protected:
    int a1;
    int l, b;
public:
    void Aa(int c, int d)
    {
        l = c;
        b = d;
        a1 = l * b;
        cout << "The area of rectangle is " << a1 << endl;
    }
};
class Brec 
{
protected:
    int a2, l;

public:
    void Ab(int c)
    {
        l = c;
        a2 = l * l;
        cout << "The area of square is " << a2 << endl;
    }
};

class Crec : public Brec, public Arec
{
    int a3;

public:
    // int a3;
    void Ac()
    {
        cout << "The sum of the areas is: "<<(a3 = a1 + a2) << endl;
    }
};
int main()
{
    Crec b;
    b.Aa(10, 20);
    b.Ab(9);
    b.Ac();
    return 0;
}