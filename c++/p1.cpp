#include <iostream>
using namespace std;
struct student
{
    int age, roll;
    char name[100];
    // char adrs[100];
};
void display(student);
void disp(student);
void displ(student);
int main()
{
    int n, i;
    cout << "enter the entries" << endl;
    cin >> n;
    struct student s1[n];
    for (i = 0; i < n; i++)
    {
        cin >> s1[i].age >> s1[i].roll >> s1[i].name;
    }
    display(s1[0]);
    display(s1[1]);
    disp(s1[0]);
    displ(s1[0]);
     disp(s1[1]);
    displ(s1[1]);
    return 0;
}
void display(student s1)
{
    cout << "the details are: " << endl;
    cout << s1.age << endl;
    cout << s1.roll << endl;
    // cout << s1.adrs << endl;
    cout << s1.name << endl;
}
void disp(student s1)
    {
        if (s1.age == 14)
        {
            cout << "ages 14 are of "<<s1.name << endl;
        }
        else
        {
            //cout << "no one of age 14" << endl;
        }
    }
    void displ(student s1)
    {
        if (s1.roll % 2 == 0)
        {
            cout << "even rollies are "<<s1.name << endl;
        }
        else
        {
            cout << "no one of even roll number" << endl;
        }
    }