#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>


int main(){

    char* s = get_string("s: ");
    char* t = malloc(strlen(s)+1);

    for(int i=0;i<=strlen(s);i++){
        t[i]=s[i];
    }
    // t[strlen(s)] ='\0';
    strcpy(t,s);

    if(strlen(t)>0){
        t[0] = toupper(t[0]);
    }
    // t[0] = toupper(s[0]);

    printf("%s\n",s);
    printf("%s\n",t);
    free(t);
    return 0;
}