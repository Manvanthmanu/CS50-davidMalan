#include <stdio.h>
#include <cs50.h>

int main(int argc , string argv[]){
    int n = atoi( argv[1]);
    do{
        n = get_int("Height: ");
    }while (n<=0);


    for(int i = 1;i<=n;i++){
        for(int j = n;j>0;j--){
            if(j==i){
                for(int k = 1;k<=n-(n-j);k++){
                    printf("#");
                }
                break;
            }else{
                printf(" ");
            }
            
        }
        printf(" ");
        for(int k=1;k<=i;k++){
            printf("#");
        }
        printf("\n");
    }
}