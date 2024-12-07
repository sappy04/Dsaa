#include <iostream>
using namespace std;
int main()
{
    int amount = 1341;
    int note100 = 0, note50 = 0, note20 = 0, note10 = 0, note1 = 0;
    int act_amount = amount;
    int options = 1;
    while (options <= 5)
    {
        switch (options)
        {
        case 1:
            note100 = act_amount / 100;    // kota note lagbe
            act_amount = act_amount % 100; // koto due ache total amount e
            cout << "required RS100 note are: " << note100 << endl;
            break;
        case 2:
            note50 = act_amount / 50;     // kota note lagbe
            act_amount = act_amount % 50; // koto due ache total amount e
            cout << "required RS50 note are: " << note50 << endl;
            break;

        case 3:
            note20 = act_amount / 20;
            act_amount = act_amount % 20;
            cout << "required RS20 note are: " << note20 << endl;
            break;

        case 4:
            note10 = act_amount / 10;
            act_amount = act_amount % 10;
            cout << "required RS10 note are: " << note10 << endl;
            break;

        case 5:
            note1 = act_amount;
            cout << "required RS1 note are: " << note1 << endl;
            break;
        default:
            cout << "invalid option" << endl;
            break;
        }
        options++;
    }
    return 0;
}