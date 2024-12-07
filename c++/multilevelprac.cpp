#include<iostream>
using namespace std;
class roll
{
    public:
    double rolln;
    void gr(double r)
    {
        rolln=r;
    }
    void ar()
    {
        cout<<"the roll number"<<rolln<<endl;
    }
};
class exam:public roll
{
    public:
    double math,physics;
    void inp(double m,double p)
    {
        math=m;
        physics=p;
        cout<<"the maths mark: "<<math<<" "<<"the physics mark: "<<physics<<endl;
    }
};
class eval:public exam
{
    public:
    double avg;
    void cal()
    {
        avg=(math+physics)/2;
        cout<<"the avg is: "<<avg<<endl;
    }
};
int main()
{
    eval e;
    e.gr(2178);
    e.ar();
    e.inp(99,100);
    e.cal();
return 0;
}