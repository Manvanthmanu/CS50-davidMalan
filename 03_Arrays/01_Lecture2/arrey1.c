#include <stdio.h>
#include <cs50.h>
    
const int N = 3;

float average(int length , int array[]);
int main(){
    int scores[N];
    // scores[0]=get_int("Score: ");
    // scores[1]=get_int("Score: ");
    // scores[2]=get_int("Score: ");

    for(int i = 0;i<N;i++){
        scores[i]= get_int("Score: ");
    }


    printf("Average: %f\n" ,average(N,scores));
    return 0;
}

float average(int length , int array[]){
    //calculate average
    int sum = 0;
    for ( int i = 0 ; i<length ; i++){
        sum+= array[i];
    }
    return sum/(float) length;
}