// #include<stdio.h>

// int main() {
//     int ch;
//     for(ch='A';ch<='Z';ch++){
//         putchar(ch);
//     }
// }

#include<stdio.h>
#include<string.h>

//int main() {
//    char *str="Hello";
//    printf("%d",strlen(str));
//    return 0;
//}

//#include<stdio.h>

//int main(){
//    int gpa,*p1,**p2;
//    gpa=10;
//    p1=&gpa;
//    p2=&p1;
//    printf("%d\n",*p1);
//    printf("%d",**p2);
//}

//#include<stdio.h>

//int main(){
//    int *p,sum=0,i;
//    int x[5]={1,2,3,4,5};
//    p=x;
//    for(i=0;i<5;i++){
//        sum=sum+*p;
//        p++;
//    }
//    printf("%d",sum);
//}

#include<stdio.h>

int main(){
    int n,*p;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        int b;
        scanf("%d",&b);
        a[i]=b;
    }
    for(int c=0;c<n;c++){
        printf("%d",a[c]);
    }
    
    p=a;
    for(int j=0;j<n;j++){
        if(a[j]>*p){
            *p=a[j];
        }
    }
    printf("%d",*p);
    return 0;
}
















