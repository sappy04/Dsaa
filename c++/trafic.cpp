#include <stdio.h>
#include <unistd.h>

int main() {
    int RED, YELLOW, GREEN;
    scanf("%d %d %d",&RED, &YELLOW, &GREEN);
    while (1) {
        printf("Red light\n");
        sleep(RED);

        printf("Yellow light\n");
        sleep(YELLOW);
      
        printf("Green light\n");
        sleep(GREEN);

        int ch;
        printf("Do you want to continue(1/0)\n");
        scanf("%d",&ch);
        if(ch == 0) break; 
    }

}