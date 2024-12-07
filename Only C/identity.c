// #include <stdio.h>

// // Function to check if a 3x3 matrix is an identity matrix
// int isIdentityMatrix(int matrix[3][3]) {
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             if (i == j) {
//                 // Diagonal elements should be 1
//                 if (matrix[i][j] != 1) {
//                     return 0;
//                 }
//             } else {
//                 // Non-diagonal elements should be 0
//                 if (matrix[i][j] != 0) {
//                     return 0;
//                 }
//             }
//         }
//     }
//     return 1;
// }

// int main() {
//     int matrix[3][3];

//     // Input the matrix elements
//     printf("Enter the elements of the 3x3 matrix:\n");
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             scanf("%d", &matrix[i][j]);
//         }
//     }

//     // Check if the matrix is an identity matrix
//     if (isIdentityMatrix(matrix)) {
//         printf("The matrix is an identity matrix.\n");
//     } else {
//         printf("The matrix is not an identity matrix.\n");
//     }

//     return 0;
// }


#include<stdio.h>
int identity(int matrix[3][3])
{
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==j)
            {
                if(matrix[i][j]!=1)
                return 0;
            }
            else
            {
                if(matrix[i][j]!=0)
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int matrix[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    if(identity(matrix))
    {
        printf("identity");
    }
    else
    {
        printf("not an identity matrix");
    }
    return 0;
}




