#include <stdio.h>
#include <cs50.h>

int main(void){
    string username = get_string("Please enter your name : ");
    printf("hello, %s",username);
}