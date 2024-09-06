#include <stdio.h>
#include <math.h>

int count(long long int number){
    int count = 0;
    while(number > 0){
        count++;
        number = number / 10;
    }
    return count;
}

long long int power( int value , int powerNum  ){
    return round(pow(value, powerNum));
}

long long int reverse(long long int cardnum , int length ){
    long long int temp = 0;

    for(int i = 1 ; i<=length ; i++ ){
        long long int tenspower = power(10 , ( length - i)) ;

        long long int digit = cardnum/tenspower;

        temp = temp + ( digit * power(10 , (i-1) ));

        cardnum = cardnum - (tenspower*digit); 

    }

    return temp;
}



int main(){



    long long int num = 4003600000000014;

    int length = count(num);
    long long int reverseNum = reverse(num , length);

    int sum = 0 ;
    int check = 0;

    printf("%lld\n" , reverseNum);

    for(int i=1; i<=length ;i++){
        long long int tenspower = power(10 , ( length - i)) ;

        long long int digit = reverseNum/tenspower;

        if(i%2==0){
            sum = digit*2;
            check = check +  (sum*power(10 , (i-1)));
        }
        reverseNum = reverseNum - (tenspower*digit); 

        // printf("%d\n" , digit);

    }
    
    printf("\n%d", sum);
    return 0;
}