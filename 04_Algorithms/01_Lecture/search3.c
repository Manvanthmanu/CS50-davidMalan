#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(){

    string names[] = {"manvnth","kushi","anu","charan"};
    int number[]={123,1342,134432,2444,1234};

    string name = get_string("Name: ");
    for(int i = 0;i<3;i++){
        if(strcmp(names[i],name)==0){
            printf("Found %i\n",number[i]);
            return 0;
        }
    }printf("Not found");
    return 0;
}