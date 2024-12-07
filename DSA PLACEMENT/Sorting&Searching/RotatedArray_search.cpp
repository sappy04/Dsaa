#include <iostream>
using namespace std;
int binary(int array[], int start, int end, int key)
{
    while (start <= end)
    {
        int mid = start + ((end-start)/2);
        if (array[mid] == key)
        {
            return mid;
        }
        else if (array[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
        return -1;//AREA OF CAUTION

}
int pivot(int array[], int n)
{
    int start = 0;
    int end = n - 1;
    while(start<end)
    {
        int mid = start + ((end-start)/2);
        if(array[mid]>array[mid+1])
        {
            return mid+1;
        }
        else if(array[mid]<array[end])//IMP LEARN
        {
            end=mid;//IMP learn
        }
        else
        {
            start=mid+1;
        }
    }
    return start;
}
int partition(int array[], int n, int key)
{
    int pivotindex=pivot(array,n);//binary serach ka value????
    if(key>=array[pivotindex] && key<=array[n-1])//check
    {
        return binary(array,pivotindex,n-1,key);
    }
    else
    {
        return binary(array,0,pivotindex-1,key);
    }

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
    int key;//after taking array input only take te key input else wrong answer
    cin>>key;
    int answer=partition(array,n,key);
    if(answer==-1)
    {
        cout<<"Element not found in array"<<endl;
    }
    else
    {
        cout<<"Element found at index "<<answer<<" and element is "<<array[answer]<<endl;
    }
    return 0;
}