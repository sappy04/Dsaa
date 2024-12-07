#include <iostream>
#include <bitset>
#include <string>
using namespace std;
int power(int a, int b)
{
    int answer = 1;
    for (int i = 1; i <= b; i++)
    {
        answer = answer * a;
    }
    return answer;
}
bool ispower(int a)
{
    bitset<32> binary(a);
    string str = binary.to_string();
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '1')//power of two has only one 1 present in it.
        {
            count++;
        }
    }
    if (count == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int a;
    int b;
    int checknum;
    cout << "Enter the base and power: ";
    cin >> a;
    cin >> b;
    cout << power(a, b) << endl;

    cout << "enter the number to be checked if it a power of 2" << endl;
    cin >> checknum;
    if (ispower(checknum))
    {
        cout << "yes it is a power of 2" << endl;
    }
    else
    {
        cout << "No!! it is not a power of 2" << endl;
    }
    return 0;
}