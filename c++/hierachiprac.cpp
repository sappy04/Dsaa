#include<iostream>
using namespace std;
class num
{
    // protected:
    
    public:
    double numu;
    double getn(double n)
    {
        numu=n;
        cout<<"the num in base: "<<numu<<endl;
    }
    
};
class cube:public num
{
//    protected:

    public:
    double a;
    double ar()
    {
        a=(numu*numu*numu);
        cout<<"cube"<<" "<<a<<endl;
    }

};
class square:public num
{
//    protected:

    public:
    double a;
    double rar()
    {
        a=(numu*numu);
        cout<<"square"<<" "<<a<<endl;
    }
};
int main()
{
    num m;
    m.getn(5);
    cube c;
    c.getn(5);
    c.ar();
    square s;
    s.getn(5);
    s.rar();
return 0;
}