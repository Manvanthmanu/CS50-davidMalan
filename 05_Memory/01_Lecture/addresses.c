#include <stdio.h>

int main(void){

    long int n = 50;
    int f=3899;
    long int *ptr =&n;
    long int **ptrr = &ptr;
    printf("%i - %i - %i\n",*(&n),**ptrr,n);
}