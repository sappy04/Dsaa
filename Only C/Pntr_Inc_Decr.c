#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int ar[n];
    printf("Enter the number of elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    int *ptr=ar;
    printf("\nArray elements using pointer increment: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",*ptr);
        ptr++;
    }
   ptr--;
    printf("\nArray elements using pointer decrement: ");
    for(int i=n-1;i>=0;i--)
    {
        printf("%d ",*ptr);
        ptr--;
    }
    return 0;
}