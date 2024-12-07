#include <iostream>
using namespace std;
struct student
{
    int roll;
    float marks;
    char name[100];
};
int main()
{
    int n;
    cout << "enter the number of datas you want to enter" << endl;
    cin >> n;
    int total = 0;
    float avg = 0;
    struct student s1[n];
    for (int i = 0; i < n; i++)
    {
        cout << "enter the roll number" << endl;
        cin >> s1[i].roll;
        cout << "enter the marks" << endl;
        cin >> s1[i].marks;
        cout << "enter the name" << endl;
        cin >> s1[i].name;
        total = total + s1[i].marks;
        avg = total/n;
    }
    cout << "The roll of the student is" << endl;
    cout << s1[1].roll << endl;
    cout << "The marks of the student is" << endl;
    cout << s1[1].marks << endl;
    cout << "The name of the student is" << endl;
    cout << s1[1].name << endl;
    cout << "The total marks of the student is" << endl;
    cout << total << endl;
    cout << "The avg marks of the student is" << endl;
    cout << avg << endl;

    return 0;
}