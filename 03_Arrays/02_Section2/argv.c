#include <stdio.h>
#include <cs50.h>

int main(int argc , string argv[]){

    for(int i = 0;i<argc;i++){
        printf("\n%s" , argv[i]);
    }
    return 0;
}