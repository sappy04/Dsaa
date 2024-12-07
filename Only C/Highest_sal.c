#include <stdio.h>
#include <string.h>
struct employee
{
    int num;
    char name[100];
    float sal;
};
int main()
{
    int n;
    int index=0;
    float h_sal = 0.0;

    printf("Enter the number of employees: ");
    scanf("%d", &n);
    struct employee emps[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the employee details: \n");
        printf("Enter the employee number: ");
        scanf("%d", &emps[i].num);
        printf("Enter the employee name: ");
        scanf("%s", emps[i].name);
        printf("Enter the employee salary: ");
        scanf("%f", &emps[i].sal);

        if(emps[i].sal>h_sal)
        {
            h_sal = emps[i].sal;
            index=i;
        }
    }
    printf("The employee with the highest salary is: %s, whose id is: %d and salary is: %f",emps[index].name,emps[index].num,emps[index].sal);
    
    return 0;
}
