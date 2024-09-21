#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int LinearSearch(int n , int array1[],int arreysize);

int main(){

    int array1[] = {10,8,7,6,1,4,1,9,19,12};
    int arreysize=sizeof(array1)/sizeof(array1[0]);


  
    printf("The index is %d\n", LinearSearch(12,array1,arreysize));
    return 0;
}

int LinearSearch(int n ,int array1[],int arreysize){

    for(int i = 0;i<arreysize;i++){
        if(array1[i]==n){
            printf("Search Found\n");
            return i;
        }
    }
    printf("Not found\n");
    return -1;
}
