#include <iostream>
#include <string>
using namespace std;

// function

// int sum(int a, int b)
// {
//     int c = a + b;
//     return c;
// }
// int prod(int a, int b)
// {
//     int c = a * b;
//     return c;
// }

//constructors
// class rectangle
//  {
//     public: int l,b;
//     rectangle()//default constructor
//     {
//          l=0; b=0;
//     }
//     rectangle(int x,int y)//parameterized constructor
//     {
//         l=x;
//         b=y;
//     }
//     rectangle(rectangle &r)//copy constructor
//     {
//         l=r.l;
//         b=r.b;
//     }
// // destructor
//         ~rectangle()
//         {
//             cout<<"destructor is called"<<endl;
//         }
//  };

int main()
{
    // cout<<"Hello World Saptarshi"<<endl;
    // cout<<"Hello Annaesha"<<endl;
    // cout<<"Hello World Saptarshi'";
    // cout<<"Annaesha"<<endl;
    // int a=1;//if i use key (const a) then value printed will be only 1,jodi neeche further change kora thake tao change hobena
    // a=9;//jodi const key na thake then value update hoye jabe
    // cout<<"The vaue of a is="<<a;

    // int a;
    // cout<<"Enter the 1st no."<<endl;
    // cin>>a;
    // int b;
    // cout<<"Enter the 2nd no."<<endl;
    // cin>>b;
    // int c=a+b;
    // cout<<"The sum of the number is:"<<c<<endl;

    // conditional statements
    //     int age;
    //     cout<<"Enter your age"<<endl;
    //     cin>>age;
    //     if(age>120)
    //     {
    //      cout<<"Abhi marne walla hai";
    //     }
    //     else if(age>=18 && age<=120)
    //     {
    //      cout<<"you can drink";
    //     }
    //     else
    //     {
    //      cout<<"Dont drink";
    //     }

    // //switch
    //    int age;
    //    cout<<"Enter your age"<<endl;
    //    cin>>age;
    //    switch (age)
    //    {
    //    case 18:
    //     cout<<"indeed you are 18";
    //     break;

    //    case 12:
    //     cout<<"indeed you are 12";
    //     break;

    //    default:
    //    cout<<"you are not 18 or 12";
    //     break;
    //    }

    // int idx=0;
    // while(idx<=10)
    // {
    //     cout<<"We are at idx :"<<idx<<endl;
    //     idx++;
    // }

    // int idx=1;
    // do
    // {
    //     cout<<"We are at idx :"<<idx<<endl;
    //     idx++;
    // } while (idx>10);//wrong condition still will work one time

    // int idx=0;
    // do
    // {
    //     cout<<"We are at idx :"<<idx<<endl;
    //     idx++;
    // } while (idx<=10);//correct condition will work

    // function part
    //  int a;
    //  cout << "Enter the 1st no." << endl;
    //  cin >> a;
    //  int b;
    //  cout << "Enter the 2nd no." << endl;
    //  cin >> b;
    //  cout << "The sum of the number is:" << sum(a, b) << endl;
    //  cout << "The product of the number is:" << prod(a, b) << endl;

    // array

    // int n;
    // cout << "Enter the size of the array" << endl;
    // cin >> n;
    // int marks[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Enter the marks of the " << i << "th student" << endl;
    //     cin >> marks[i];
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Marks of the " << i << "th student is:" << marks[i] << endl;
    // }

    // 2d array
    //  int n;
    //  cout << "Enter the size of the array" << endl;
    //  cin >> n;
    //  int marks[n][n];
    //  for (int i = 0; i < n; i++)
    //  {
    //      for (int j = 0; j < n; j++)
    //      {
    //          cout << "Enter the marks of the student" << endl;
    //          cin >> marks[i][j];
    //      }
    //  }
    //  cout << "The marks of the student are :" << endl;
    //   for (int i = 0; i < n; i++)
    //  {
    //      for (int j = 0; j < n; j++)
    //      {
    //          cout << marks[i][j]<<endl;
    //      }
    //  }

    // string
    //  string name="ANNAESHA DEBNATH";
    //  cout<<"The name of my sweet heart is: "<<name<<" <3 !! "<<endl;
    //  cout<<"The length of the name is: "<<name.length()<<endl;//starts from 1
    //  cout<<"The substring of the name is: "<<name.substr(3)<<endl;
    //  cout<<"The substring of the name is: "<<name.substr(0,12)<<endl;//11 is B
    //  string name="Annaesha";
    //  cout<<"The name of my sweet heart is: "<<name<<" <3 !! "<<endl;
    //  cout<<"The length of the name is: "<<name.length()<<endl;//starts from 1
    //  cout<<"The substring of the name is: "<<name.substr(3)<<endl;
    //  cout<<"The substring of the name is: "<<name.substr(0,4)<<endl;

    // pointers
    //    int a=1003;
    //    int *ptr=&a;
    //    cout<<"Value of a is: "<<a<<endl;
    //    cout<<"Value of a is: "<<*ptr<<endl;//*means value at address of and &address of
    //    cout<<"The address of a is: "<<&a<<endl;
    //    cout<<"The address of a is: "<<ptr<<endl;

    //constructor part
    // rectangle r1;
    // cout<<r1.l<<" "<<r1.b<<endl;
    // rectangle r2(4,5);
    // cout<<r2.l<<" "<<r2.b<<endl;
    // rectangle r3=r2;
    // cout<<r3.l<<" "<<r3.b<<endl;

//destructor
    // rectangle *r1=new rectangle();//new keyword works only with pointers
    // cout<<r1->l<<" "<<r1->b<<endl;
    // delete r1;
    // rectangle r2(4,5);
    // cout<<r2.l<<" "<<r2.b<<endl;
    // rectangle r3=r2;
    // cout<<r3.l<<" "<<r3.b<<endl;
    return 0;
}