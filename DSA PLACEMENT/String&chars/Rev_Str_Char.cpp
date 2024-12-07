// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     char name[100];
//     cin >> name;
//     int length = strlen(name);
//     reverse(name, name + length);
//     cout << name << endl;

//     string name1;
//     getline(cin,name1);
//     reverse(name1.begin(), name1.end());
//     cout << name1;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
void reverse(char name[],int length)
{
    int start=0;
    int end=length-1;
    while(start<end)
    {
        swap(name[start],name[end]);
        start++;
        end--;
    }
    cout<<name<<endl;
}
int len(char name[])
{
    int count=0;
    for(int i=0;name[i]!='\0';i++)
    {
        count++;
    }
    return count;
}
int main()
{
    char name[100];
    cin>>name;
   
    int length = len(name);
    reverse(name,length);
    return 0;
}