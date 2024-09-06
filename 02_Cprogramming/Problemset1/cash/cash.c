#include <stdio.h>
#include <cs50.h>

int main(void){

    //  25 , 10 , 5 , 1
    int change;
    do{

       change = get_int("Change owed: ");  
    }while(change<0);
    
    int coins =0;

    if(change<5){
        coins=coins+change;
        printf("%d" , coins);
    }
    else{

        if(change/25!=0)
        {
            coins = coins + (change/25);
            change = change - (coins*25);

            if(change/10!=0)
            {
                coins = coins + (change/10);
                int thiscoin = change/10;
                change = change - ( thiscoin*10 );



                if(change/5!=0)
                {
                    coins = coins +(change/5);
                    int thiscoin = change/5;
                    change = change - ( thiscoin*5);


                    if(change<5)
                    {
                        coins = coins+change;

                    }
                } else{
                    coins =coins+change;
                }
            }else if(change/5!=0){
                coins = coins +(change/5);
                    int thiscoin = change/5;
                    change = change - ( thiscoin*5);


                    if(change<5)
                    {
                        coins = coins+change;

                    }
                
            }else{
                coins = coins+change;
            }

        }else if(change/10!=0){
            coins = coins + (change/10);
                int thiscoin = change/10;
                change = change - ( thiscoin*10 );
                if(change/5!=0)
                {
                    coins = coins +(change/5);
                    int thiscoin = change/5;
                    change = change - ( thiscoin*5);


                    if(change<5)
                    {
                        coins = coins+change;

                    }
                }else{
                    coins = coins+change;
                }
        }else{
            coins = coins+1;
            change = change-5;
        }

        printf("%d" ,coins);

    }
}