#include<iostream>
using namespace std;
class sera
{
    public:
    int a,b;
    sera(void);//constructor declaration
    void pn()
{
    cout<<"value of a: "<<a<<"value of b: "<<b<<endl;
}
};
sera ::sera(void)//constructor defination
{
     a=10;
     b=20;
}

int main()
{
    sera s1;
    s1.pn();
    return 0;
}
