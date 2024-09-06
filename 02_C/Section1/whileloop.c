#include <stdio.h>

int main(){

    int j = 0;
    for(int i = 0;i<=4;i++){
    
        while (j<=4)
        {
            if(j==4){
                printf("#");
            }else{
                printf("-");
            }
            j++;
        }
        printf("\n");
    }
    
    return 0;
}