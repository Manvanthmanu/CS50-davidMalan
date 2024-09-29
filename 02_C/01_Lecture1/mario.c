
#include <stdio.h>

int blocks();

int main(void){
    for(int i=0;i<4;i++)
    printf("?");

    printf("\n");
    blocks();
}

int blocks(){

    int n;

    // Prompt user for positive integor
    do
    {
        printf("Please enter the blocks : ");
        scanf("%d",&n);
    } while (n<1);
    
    //  Prompt an n-by-n grid of bricks 
    for (int i = 0 ;i<n;i++){
        for(int j = 0;j<n;j++){
            printf("#");
        }
        printf("\n");
    }
}