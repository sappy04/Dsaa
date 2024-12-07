#include<iostream>
using namespace std;
int pivot(int array[],int n)
{
    int start=0;
    int end=n-1;
    while (start<end)
    {
        int mid=start+((end-start)/2);
        if(array[mid]>array[mid+1])
        {
            return (mid+1);
        }
        else if(array[mid]<array[end])
        {
            end=mid;
        }
        else if(array[mid]>array[end])
        {
            start=mid+1;
        }
    }
    return start;
    
}
int main()
{
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    int answer=pivot(array,n);
    cout<<"pivot is at index: "<<answer<<" and element is: "<<array[answer]<<endl;
return 0;
}