#include<stdio.h>
#include<string.h>
struct book
{
    int id;
    char name[200];
    char author[100];
};
int bc=0;
struct book bk[100];
void add()
{
    printf("Enter the id:");
    scanf("%d",&bk[bc].id);
    printf("Enter the name:");
    scanf(" %[^\n]",bk[bc].name);
    printf("Enter the author:");    
    scanf(" %[^\n]",bk[bc].author);
    bc++;
}
void display()
{
    if(bc==0)
    {
        printf("No books in the list");
    }
    for(int i=0;i<bc;i++)
    {
        printf("Book id:%d\nBook name:%s\nBook author:%s",bk[i].id,bk[i].name,bk[i].author);
    }
}
void list()
{
    char auth[100];
    printf("Enter the author name:");
    scanf(" %[^\n]",auth);
    int found=0;

for(int i=0;i<bc;i++)
{
    if(strcmp(auth,bk[i].author)==0)
    {
        printf("Book id:%d\nBook name:%s",bk[i].id,bk[i].name);
        found=1;
    }
}
if(!found)
{
    printf("No books by this author");
}
}
int main()
{
    int ch;
    do
    {
       printf("\n1.add\n2.display\n3.list\n4.count\n5.exit\nEnter your choise: ");
       scanf("%d",&ch);
       switch (ch)
       {
       case 1:add();break;
       case 2:display();break;
       case 3:list();break;
       case 4:printf("total no. of books %d",bc);break;
       case 5:printf("exiting...");break;       
       default:
        printf("Invalid choice");
       }
    } while (ch!=5);
    return 0;
}