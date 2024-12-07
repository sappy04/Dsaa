#include <bits/stdc++.h>
using namespace std;
void sortkaro(int array[], int n)
{
    bool swapped = false;//flag
    for (int i = 0; i < (n - 1); i++)//rounds bhai no.of elements -1 hi hota hai(universal)...
    {
        for (int j = 0; j < (n - 1 - i); j++)//full range comparison with optimazation of not checking the last sorted element
        {
            if (array[j] > array[j + 1])//agar pehla dusre se badha hai
            {
                swap(array[j], array[j + 1]); // ghappa ghap swap
                swapped=true;
            }
        }
    }
    if(swapped==true)
    {
        cout<<"sorted"<<endl;
    }
    else
    {
        cout<<"already sorted"<<endl;
    }
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<" ";
    }
}
int main()
{
    int n;
    cin >> n;
    int array[100];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    sortkaro(array, n);
    return 0;
}



// #include <iostream>
// using namespace std;
// void sorting(int array[], int n)
// {
//     bool issorted = false;            // to check if already sorted
//     for (int i = 0; i < (n - 1); i++) // displays the round. 0 to n-1 rounds(Universal)..this loop is only for rounds
//     {
//         for (int j = 0; j < (n - i - 1); j++) // n-i is for excluding the last sorted element in each round.
//         {
//             if (array[j] > array[j + 1]) // compare all the adjacent elements side by side and not with all elements in the array
//             {
//                 swap(array[j], array[j + 1]); // swaap if bigger number(a>b)
//                 issorted = true;
//             }
//         } // for every false condition of for,this if condition will be checked
//         if (issorted == false) // works hands in hands with i loop
//         {
//             cout << "already sorted!!" << endl;
//             break;
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cout << array[i] << " ";
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int array[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> array[i];
//     }
//     sorting(array, n);
//     return 0;
// }