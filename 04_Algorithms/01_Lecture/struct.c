#include <stdio.h>
#include <cs50.h>
#include <string.h>


typedef struct
{
    string name;
    int num;
}phonebook;

int main(){
    string names[] = {"manvnth","kushi","anu","charan"};
    int number[]={123,1342,134432,2444,1234};

    phonebook name[10];
    name[0].name="Manvanth";
    name[0].num = 12344;

    for(int i = 1;i<4;i++){
        name[i].name = names[i];
        name[i].num = number[i];
        printf("name : %s;\nnum :%i\n" , name[i].name , name[i].num);
    }
    return 0;
}