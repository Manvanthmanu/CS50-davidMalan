#include <stdio.h>
#include <cs50.h>

int main(){

    char c = get_char("Do you agree? ");
    if(c =='y' || c=='Y'){
        printf("Agreed.\n");
    }
    else if(c=='n'|| c=='N'){
        printf("Not agreed.\n");
    }
    else{
        printf("wrong input ; ");
    }

    return 0;
}