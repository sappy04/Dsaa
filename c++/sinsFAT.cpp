#include<iostream>
using namespace std;
struct student
{
    int age;
    char name[100];
    char id[100];
};
struct cource
{
    char ncource[100];
    int ducource;
    student stu;
};
int main()
{
    int n;
    cout<<"enter the data to be entered"<<endl;
    cin>>n;
    struct cource c[n];
    for(int i=0;i<n;i++)
    {
    cout<<"enter the couce name"<<endl;
    cin>>c[i].ncource;
    cout<<"enter the couce duration"<<endl;
    cin>>c[i].ducource;
    cout<<"enter the age of student"<<endl;
    cin>>c[i].stu.age;
    cout<<"enter the name of student"<<endl;
    cin>>c[i].stu.name;
    cout<<"enter the id of student"<<endl;
    cin>>c[i].stu.id;
    }
    for(int i=0;i<n;i++)
    {
    cout<<"the cource name of the student is : "<<c[i].ncource<<endl;
    cout<<"the cource duration of the student is : "<<c[i].ducource<<endl;
    cout<<"the name of the student is : "<<c[i].stu.age<<endl;
    cout<<"the id of the student is : "<<c[i].stu.name<<endl;
    cout<<"the age of the student is : "<<c[i].stu.id<<endl;
    }
return 0;
}
/*You are tasked with developing a program to manage
student records for a university. Each student record
contains information about the student, including their
personal details and academic performance. Additionally,
each student has a structure within the main structure to
store their course information. Write a C program to define
a structure named 'Student' that represents a student's
record. The 'Student' structure should have fields for the
student's name, ID, age, and a nested structure named
'Course' that holds the student's course details, such as the
course name and grade. Implement the program to create
an array of 'Student' structures and display the details of all
the students along with their respective course details.*/