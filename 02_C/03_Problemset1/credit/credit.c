#include <stdio.h>
#include <string.h>
// #include <cs50.h>

int main(void){


    long long int n = 349999999999999;
    long long int tn = n;

    

    int count = 0;
    printf("%lld\n" , n);

    while(tn>0){
        count++;
        tn=tn/10;
    }
    if(count==15 && ((n >= 340000000000000  && n <= 349999999999999) || 
                    (n >= 370000000000000  && n <=379999999999999 ))) {
        printf("AMEX\n");
    }else if(count==16 ){
        if(n>5100000000000000 && n<5599999999999999){
            printf("MASTERCARD\n");
        }else if(n>=4000000000000000 && n<5000000000000000){
            printf("VISA\n");
        }else{
            printf("INVALID\n");
        }
    }else if(count==13 && (n>=4000000000000 && n<5000000000000)){
        printf("VISA\n");
    }else{
        printf("INVALID\n");
    }

    printf("%d", count);
}