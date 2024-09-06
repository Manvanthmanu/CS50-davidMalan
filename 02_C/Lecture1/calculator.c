#include <stdio.h>

int add(int a,int b);
int main(){

    int x , y;
    printf("Enter the number : ");
    scanf("%d",&x);
    printf("Enter the number : ");
    scanf("%d",&y);

    printf("%i\n",x+y);
    printf("the additiion is %d ;" , add(x,y));
    return 0;
}

int add(int a , int b){
    return a+b;
}