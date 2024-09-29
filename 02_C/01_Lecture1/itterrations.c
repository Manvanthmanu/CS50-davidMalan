#include <stdio.h>

int main(){

    int manu=8;
    while(manu>0){
        printf("%d\n",manu);
        manu--;
    }
    char str1[]="hello";

    for(int i = 0;i<3;i++){
        printf("%s\n",str1);
    }

    int hey= 0;
    while(1){
        printf("hello world %d\n" , hey);
        if(hey==10){
            break;
        }
        hey++;
    }
    return 0;
}