// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     char name[100];
//     cin>>name;
//     int length=strlen(name);
//     cout<<"Length of the string is "<<length<<endl;
// return 0;
// }


#include<bits/stdc++.h>
using namespace std;
void countlength(char name[])
{
    int count=0;
    for(int i=0;name[i]!='\0';i++)
    {
        count++;
    }
    cout<<"Length of the string is "<<count<<endl;
}
int main()
{
    char name[100];
    cin>>name;
    countlength(name);
    return 0;
}