#include <iostream>
#include <algorithm>
using namespace std;
void rev(string str, int arr[], int n)
{
    reverse(str.begin(), str.end());
    cout << "\nreversed string is: " << str << endl;

    cout << "reversed array is: ";
    for (int i = n - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    string str;
    cin >> str;
    cout << "original string is: " << str << endl;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "original array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    rev(str, arr, n);

    return 0;
}


        //REVERSE ARRAY INTEGER!!


        
// #include <iostream>
// using namespace std;
// void reverse(int ar[], int n)
// {
//     int start = 0;
//     int end = n - 1;

//     while (start <= end)
//     {
//         swap(ar[start], ar[end]);
//         start++;
//         end--;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cout << ar[i] << " ";
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int ar[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> ar[i];
//     }
//     reverse(ar, n);
//     return 0;
// }


        //reversing a number from desired location!!



        
// #include <iostream>
// using namespace std;
// void reverse(int ar[], int n,int index)
// {
//     int start=index+1;
//     int end=n-1;
   
//         while(start<=end)
//         {
//             swap(ar[start],ar[end]);
//             start++;
//             end--;
//         }
   


//     for (int i = 0; i < n; i++)
//     {
//         cout << ar[i] << " ";
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int ar[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> ar[i];
//     }
//     int index;
//     cin>>index;
//     reverse(ar, n,index);
//     return 0;
// }