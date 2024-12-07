#include <iostream>
using namespace std;
class Roll
{
protected:
    int rn;
public:
    int grn(int r)
    {
        rn = r;
    }
    void srn(void)
    {
        cout << "The roll number is: " << rn << endl;
    }
};
class Exam:public Roll
{
protected:
    float maths;
    float physics;

public:
    float gm(float m1, float m2)
    {
        maths = m1;
        physics = m2;
    }
    void sm(void)
    {
        cout << "The marks in maths is: " << maths << "\nThe marks in physics is: " << physics << endl;
    }
};
class Eval : public Exam 
{
protected:
    float avg;
public:
    void dis()
    {
        avg = (maths + physics) / 2;
        cout << "The % is " << avg << endl;
    }
};

int main()
{

    Eval v;
    v.grn(2178);
    v.srn();
    v.gm(90.45,78.45);
    v.sm();
    v.dis();

    return 0;
}
