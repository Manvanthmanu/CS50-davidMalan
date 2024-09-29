#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(){

    string phrase = get_string("Enter a phrase : ");
    
    int length = strlen(phrase);
    for(int i = 0;i<length;i++ ){
        // check if characters are not in alphabetical order;
       
        if(i==length-1){
            break;
        }else{
            if(phrase[i]>phrase[i+1]){
                printf("Not in alphabetical order.\n");
                return 0;
            }
        }
    }
    printf("These are in alphabetical order \n");

    return 0;
}