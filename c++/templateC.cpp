#include<iostream>
using namespace std;
template<typename T ,typename U >
class weig
{
    private: 
    T kg;
    U gm;
    public:
    U sd(T x,U y)
    {
        kg=x;
        gm=y;
        cout<<(kg+gm)<<endl;
    }
    T gdk()
    {
        return kg;
    }
    U gdg()
    {
        return gm;
    }
};
int main()
{
    weig<int,double>obj1;
    obj1.sd(100,0.50);
    cout<<"The kgs is "<<obj1.gdk()<<endl;
    cout<<"The gms is "<<obj1.gdg()<<endl;
return 0;
}