#include <stdio.h>
#include <cs50.h>

int str_len(string k);
int main(){

    string words[2];

    words[0]="Hi!";
    words[1]="Bye!";

    printf("%c%c%c\n" , words[0][0] , words[0][2], words[0][1]);
    printf("%i" , str_len(words[1]));
    return 0;
}

int str_len(string k){
    int i = 0;
    while(k[i]!='\0'){
        i++;
    }
    return i;
}