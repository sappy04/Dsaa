#include<iostream>
using namespace std;
class area
{
    //private:
    
    public:
    double len,bre;
    // void gd();
    // void disp();
    void gd()
    {
        cout<<"Enter the l and b"<<endl;
        cin>>len>>bre;
    }
    void disp()
    {
        cout<<"the len and braedth is"<<endl;
        cout<<len<<" "<<bre<<endl;
    }
};
class rec:public area
{
    public:
    //void cal();
    void cal()
    {
        double area=len*bre;
        cout<<area<<endl;
    }
};
// void rec::cal()
// {
//     double area=len*bre;
//     cout<<area<<endl;
// }
// void area::gd()
// {
//     cout<<"Enter the l and b"<<endl;
//     cin>>len>>bre;
// }
// void area::disp()
// {
//         cout<<"the len and braedth is"<<endl;
//         cout<<len<<" "<<bre<<endl;
// }
int main()
{
    rec r;
    r.gd();
    r.disp();
    r.cal();
    return 0;
}