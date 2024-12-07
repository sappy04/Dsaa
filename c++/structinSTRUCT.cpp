// // #include<iostream>
// // using namespace std;

// // struct addr
// // {
// //    int houseno;
// //    string area;
// //    string city;
// //    string state;
// // };
// // struct emp
// // {
// //    int id ;
// //    string name;
// //    addr address;            // complex element
// // } ;

// // int main()
// // {
// //    emp e;

// //    cout<<"Enter the ID: ";
// //    cin>>e.id;
// //    cout<<"Enter the Name: ";
// //    cin>>e.name;
// //    cout<<"Enter the House No.: ";
// //    cin>>e.address.houseno;
// //    cout<<"Enter the Area: ";
// //    cin>>e.address.area;
// //    cout<<"Enter the City: ";
// //    cin>>e.address.city;
// //    cout<<"Enter the State: ";
// //    cin>>e.address.state;

// //    cout<<"\n\nEmployee ID: "<<e.id;
// //    cout<<"\nEmployee Name: "<<e.name;
// //    cout<<"\nAddress: ";
// //    cout<<e.address.houseno<<", "<<e.address.area<<", "<<e.address.city<<", "<<e.address.state;
// //    cout<<endl;

// //    return 0;
// // }
// #include <iostream>
// using namespace std;

// struct details
// {
//     float w;
//     float h;
//     int age;
// };
// struct dob
// {
//     int date, year;
//     char month[100];
//     details del; // complex element
// };
// int main()
// {
//     struct dob d;
//     cout << "Enter the weight of the student" << endl;
//     cin >> d.del.w;
//     cout << "Enter the heigth of the student" << endl;
//     cin >> d.del.h;
//     cout << "Enter the age of the student" << endl;
//     cin >> d.del.age;
//     cout << "Enter the date of the birth of the student" << endl;
//     cin >> d.date;
//     cout << "Enter the year of the birth of the student" << endl;
//     cin >> d.year;
//     cout << "Enter the month of the birth of the student" << endl;
//     cin >> d.month;

//     cout << "The weight of the student" << endl;
//     cout << d.del.w << endl;
//     cout << "The height of the student" << endl;
//     cout << d.del.h << endl;
//     cout << "The age of the student" << endl;
//     cout << d.del.age << endl;
//     cout << "The date of the birth of the student is: " << d.date << " The year of the birth of the student is: " << d.year << " The month of the birth of the student is: " << d.month << endl;

//     return 0;
// }
// #include<iostream>
// using namespace std;

// struct addr
// {
//    int houseno;
//    string area;
//    string city;
//    string state;
// };
// struct emp
// {
//    int id ;
//    string name;
//    addr address;            // complex element
// } ;

// int main()
// {
//    emp e;

//    cout<<"Enter the ID: ";
//    cin>>e.id;
//    cout<<"Enter the Name: ";
//    cin>>e.name;
//    cout<<"Enter the House No.: ";
//    cin>>e.address.houseno;
//    cout<<"Enter the Area: ";
//    cin>>e.address.area;
//    cout<<"Enter the City: ";
//    cin>>e.address.city;
//    cout<<"Enter the State: ";
//    cin>>e.address.state;

//    cout<<"\n\nEmployee ID: "<<e.id;
//    cout<<"\nEmployee Name: "<<e.name;
//    cout<<"\nAddress: ";
//    cout<<e.address.houseno<<", "<<e.address.area<<", "<<e.address.city<<", "<<e.address.state;
//    cout<<endl;

//    return 0;
// }
#include <iostream>
using namespace std;

struct details
{
    float w;
    float h;
    int age;
};
struct dob
{
    int date, year;
    char month[100];
    details del; // complex element
};
void cal(dob);
int main()
{
    struct dob d;
    cout << "Enter the weight of the student" << endl;
    cin >> d.del.w;
    cout << "Enter the heigth of the student" << endl;
    cin >> d.del.h;
    cout << "Enter the age of the student" << endl;
    cin >> d.del.age;
    cout << "Enter the date of the birth of the student" << endl;
    cin >> d.date;
    cout << "Enter the year of the birth of the student" << endl;
    cin >> d.year;
    cout << "Enter the month of the birth of the student" << endl;
    cin >> d.month;

    cout << "The weight of the student" << endl;
    cout << d.del.w << endl;
    cout << "The height of the student" << endl;
    cout << d.del.h << endl;
    cout << "The age of the student" << endl;
    cout << d.del.age << endl;
    cout << "The date of the birth of the student is: " << d.date << " The year of the birth of the student is: " << d.year << " The month of the birth of the student is: " << d.month << endl;
    cal(d);
    return 0;
}
void cal(dob d)
{
    if(d.del.w>100)
    {
        cout<<"overweight"<<endl;
    }
    else
    {
        cout<<"under control"<<endl;
    }
}