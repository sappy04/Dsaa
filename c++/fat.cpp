/*Write a program to calculate the area of a circle. The
program should have two functions:
 A function to calculate the area of a circle with a given
radius. The function should have a default argument for the
radius of 10.
 A function to calculate the area of a circle with a given
radius and a given number of sides. The function should
have default arguments for the radius of 10 and the number
of sides of 3.
The program should then prompt the user to enter the radius
and the number of sides of the circle. The program should
then call the appropriate function to calculate the area of the
circle and print the result to the console.*/
#include<iostream>
using namespace std;
double area(int r=10)
{
    double area=(3.414*r*r); 
    cout<<"the area is"<<area<<endl;
}
double rarea(int l=10,int b=3)
{
    double area=(2*(l+b)); 
    cout<<"the area is"<<area<<endl;
}
int main()
{
    area();
    rarea();
return 0;
}