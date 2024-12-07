// #include <stdio.h>
// // Function to merge two arrays
// void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
//     int i, j;

//     // Copy elements from the first array to the merged array
//     for (i = 0; i < size1; i++) {
//         merged[i] = arr1[i];
//     }

//     // Copy elements from the second array to the merged array
//     for (j = 0; j < size2; j++) {
//         merged[i + j] = arr2[j];
//     }
// }

// int main() {
//     int size1, size2, i;

//     // Input size of the first array
//     printf("Enter the number of elements in the first array: ");
//     scanf("%d", &size1);
//     int arr1[size1];

//     // Input elements of the first array
//     printf("Enter the elements of the first array:\n");
//     for (i = 0; i < size1; i++) {
//         scanf("%d", &arr1[i]);
//     }

//     // Input size of the second array
//     printf("Enter the number of elements in the second array: ");
//     scanf("%d", &size2);
//     int arr2[size2];

//     // Input elements of the second array
//     printf("Enter the elements of the second array:\n");
//     for (i = 0; i < size2; i++) {
//         scanf("%d", &arr2[i]);
//     }

//     // Array to hold the merged result
//     int merged[size1 + size2];

//     // Merge the arrays
//     mergeArrays(arr1, size1, arr2, size2, merged);

//     // Display the merged array
//     printf("Merged array:\n");
//     for (i = 0; i < size1 + size2; i++) {
//         printf("%d ", merged[i]);
//     }
//     printf("\n");

//     return 0;
// }


#include<stdio.h>
void mergedarray(int size1,int size2,int ar1[],int ar2[],int merges[])
{
    int i,j;
    for( i=0;i<size1;i++)
    {
        merges[i]=ar1[i];
    }
    for( j=0;j<size2;j++)
    {
        merges[i+j]=ar2[j];
    }
}
int main()
{
    int i;
    int size1;
    printf("Enter the size1 :");
    scanf("%d",&size1);
    int ar1[size1];
    
    printf("Enter the elements of array1 :");
    for(i=0;i<size1;i++)
    {
        scanf("%d",&ar1[i]);
    }
    
    int size2;
    printf("Enter the size2 :");
    scanf("%d",&size2);
    int ar2[size2];
    
    printf("Enter the elements of array2 :");
    for( i=0;i<size2;i++)
    {
        scanf("%d",&ar2[i]);
    }
    
    int merges[size1+size2];
    mergedarray(size1,size2,ar1,ar2,merges);
    
    printf("The merged array is: ");
    for( i=0;i<(size1+size2);i++)
    {
        printf("%d " ,merges[i]);
    }
    
}


