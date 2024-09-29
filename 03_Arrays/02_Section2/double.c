#include <stdio.h>
#include <cs50.h>

// const int N =10;
int main(void)
{
    int N = get_int("Enter a size: ");
    int sequence[N];


    sequence[0]= 1;
        printf("%i\n", sequence[0]);


    for(int i=1;i<N;i++){
        sequence[i]= sequence[i-1]*2;
        printf("%i\n" , sequence[i]);
    }
    
}