#include <stdio.h>
#include <cs50.h>

int main(){

    string name = get_string("What is your name? ");
    int age = get_int("What is your age ? ");
    string number = get_string("What is your phone number ?");

    printf("Name :%s\nAge :%i\nNumber :%s\n" , name , age , number);
    return 0;
}