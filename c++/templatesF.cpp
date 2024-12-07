// #include<iostream>
// using namespace std;
// template<typename T,typename U>
// U mult(T x,U y)
// {
//     return(x*y);
// }
// int main()
// {
//     cout<<"multiplication of 2 numbers"<<mult<int,double>(2,4.5)<<endl;
// return 0;
// }
#include<iostream>
using namespace std;
template<typename T>
T mult(T x,T y)
{
    return(x*y);
}
int main()
{
    cout<<"multiplication of 2 numbers"<<mult<int>(2,4)<<endl;
return 0;
}