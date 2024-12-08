#include <bits/stdc++.h>
using namespace std;

int findmaxfreq(vector<int> &array, int n) // mera array jaa raha hai aur uska total size jaa raha hai
{
    int maxfreq = 0; // max count store hoga usmai
    int maxans = 0; // ismai mera charachter store hoga jiska sabse zyadaa freq hai
    unordered_map<int, int> count; // ek map banaya jismai chara->count store ho raha hai
    for (int i = 0; i < n; i++) // full array k size k lenght liya
    {
        count[array[i]]++; // count ko badahya per charachter k liye
        maxfreq = max(maxfreq, count[array[i]]); // max element ko compare krke update kar diya...freq store ho gya per charachter ka  
    } 
    for (int i = 0; i < n; i++)
    {
        if (maxfreq == count[array[i]]) // agar mera match mil jata hai pehle hi ki mera count k saty max freq mil gaya hai then print
        {
            maxans = array[i]; // charachter ko store kar diya ...mil gyaa bas print kar de
            break;
        }
    }
    return maxans; // charachter ko return kar diya 
} 

int main()
{
    vector<int> array = {1, 3, 2, 2, 1, 3, 3}; // input array
    int n = array.size(); // size of the array
    int result = findmaxfreq(array, n); // function call to find the element with max frequency
    cout << "Element with maximum frequency: " << result << endl; // result ko print kar diya
    return 0;
}
