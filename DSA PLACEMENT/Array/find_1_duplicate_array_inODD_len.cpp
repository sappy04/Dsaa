#include <iostream>
using namespace std;
void duplicateFinder(int arr[], int n)
{
    int expected_sum = ((n) * (n - 1)) / 2;       //take exapmle of 5
    int actual_sum = 0;
    for (int i = 0; i < n; i++)                 //1+2+3+4+2
    {                                           //1+2+3+4
        actual_sum += arr[i];
    }
    cout<<(actual_sum-expected_sum)<<endl;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];//need to give inputs between given range of n
    }
    duplicateFinder(arr,n);
    return 0;
}