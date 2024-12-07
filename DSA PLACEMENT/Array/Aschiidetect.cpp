#include<iostream>
using namespace std;
int main()
{
    char ch;
    cout<<"Enter a character/digit: "<<endl;
    cin>>ch;
    int ascii=int(ch);
    if(97<=ascii && ascii<=122)
    {
        cout<<"The character is a lowercase letter."<<ascii<<endl;
    }
    else if(65<=ascii and ascii<=90)
    {
        cout<<"The character is an uppercase letter."<<ascii<<endl;
    }
    else if(48<=ascii and ascii<=57)
    {
        cout<<"The character is a digit."<<ascii<<endl;
    }
    else
    {
        cout<<"The character is a special character."<<ascii<<endl;
    }
    return 0;
} 