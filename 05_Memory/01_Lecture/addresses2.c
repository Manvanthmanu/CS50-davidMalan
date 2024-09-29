#include <stdio.h>
#include <cs50.h>

int main(){

    string s = "HI!";
    printf("%p\n",s);
    printf("%p\n",&s[0]);
    printf("%p\n",&s[1]);
    printf("%p\n",&s[2]);

    return 0;
}