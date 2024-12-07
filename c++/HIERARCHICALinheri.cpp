#include <iostream>
using namespace std;
class vehicle
{
protected:
    double power;

public:
    void engine()
    {
        cout << "Enter the hp of the engine: " << endl;
        cin >> power;
        cout << "The hp of the engine is: " << power << endl;
    }
};
class tata : public vehicle
{
public:
    void power1()
    {
        cout << "The DON of vehicle industry is Tata "<<endl; 
        cout << "The torque of Tata is: " << (power * power) << endl;
    }
};
class kia : public vehicle
{
public:
    void power2()
    {
        cout << "The rising star of vehicle industry is Kia"<<endl; 
        cout << "The torque of Kia is: " << (power * 20) << endl;
    }
};
int main()
{
    tata t;
    kia k;
    t.engine();
    t.power1();
    k.engine();
    k.power2();
    return 0;
}