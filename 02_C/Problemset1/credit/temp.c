#include <stdio.h>
#include <math.h>
#include <cs50.h>


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

int print(long long int card){
    long long int n = card;
    long long int tn = n;

    

    int count = 0;
    // printf("%lld\n" , n);

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

    // printf("%d", count);
}



int main( void ){



    long long int num = get_long_long("Number: ");

    int length = count(num);
    long long int reverseNum = reverse(num , length);

    int sum = 0 ;
    long long int check = 0;
    int newsumLeftout = 0;

    // printf("%lld\n" , reverseNum);

    for(int i=1; i<=length ;i++){
        long long int tenspower = power(10 , ( length - i)) ;

        long long int digit = reverseNum/tenspower;

        if(i%2==0){
            sum = digit*2;
            check = check +  (sum*power(10 , (i-1)));
        }else{
            newsumLeftout = newsumLeftout +digit;
        }
        reverseNum = reverseNum - (tenspower*digit); 

        // printf("%d\n" , digit);

    }

    int newsumMultiplied = 0;
    int newlength = count(check);

    for(int i = 1;i<=newlength ;i++){
        long long int tenspower = power(10 , ( newlength - i)) ;

        int digit = check/tenspower;

        newsumMultiplied = newsumMultiplied + digit;

        check = check - (tenspower*digit);
    }
    
    // printf("\n%d", newsumMultiplied);
    // printf("\n%d", newsumLeftout);

    int finalvaluation = newsumLeftout +newsumMultiplied;

    if(finalvaluation%10==0){
        print(num);
    }else{
        printf("INVALID\n");
    }
}