#include <iostream>
using namespace std;
struct dob
{
    int date, year;
    char month[100];
};
void display(dob);
int main()
{
    struct dob d;
    cout << "Enter the date of the birth of the student" << endl;
    cin >> d.date;
    cout << "Enter the year of the birth of the student" << endl;
    cin >> d.year;
    cout << "Enter the month of the birth of the student" << endl;
    cin >> d.month;

    display(d);
    return 0;
}
void display(dob d)
{
    cout << "The date of the birth of the student is: " << d.date << " The year of the birth of the student is: " << d.year << " The month of the birth of the student is: " << d.month << endl;
}