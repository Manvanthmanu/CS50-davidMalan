#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int checkInput(int argc , string argv[] , int k);
char locfinder(string str1,string str2,char letter , int k);

int main(int argc , string argv[]){

// function for taking valid input ;
    int k = atoi(argv[1]);
    if(checkInput(argc, argv ,k)==1){
        return 1;
    };

// function for dividing number to 26;
    if(k>26){
        k = k- ((k/26)*26);
        printf("%d", k);
    }

// representing text;
    string lower= "abcdefghijklmnopqrstuvwxyz";
    string upper= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// input from user;
    string plainText = get_string("plaintext: ");

// length of string ;
    int length = strlen(plainText)+1;

//  Function to transverse each plaintext to parce into the cipher text ;
    char cipherText[length];

    for(int i = 0;i<length ;i++){
        if(isalpha(plainText[i])){
            
                cipherText[i]= locfinder(lower,upper,plainText[i],k);
           
        }
        else{
            cipherText[i] = plainText[i];
        }
    }
    cipherText[length] = '\0';

    printf("ciphertext: %s\n",cipherText);
    return 0;   
}

int checkInput(int argc , string argv[] , int k){
    if(argc>2){
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if(argc==1){
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for(int i =0;i<strlen(argv[1]);i++)
        if(isalpha(argv[1][i])){
            printf("Usage: ./caesar key\n");
            return 1;
    }

    if(k<0){
        printf("Usage: ./caesar key\n");
        return 1;
    }
    return 0;
}

char locfinder(string str1,string str2,char letter , int k){
    int locifupper = 0;
    int lociflower = 0;
    if(letter>=65 && letter<=90){
        for(int i = 0 ; i<=strlen(str2);i++){
            if(letter == str2[i]){
                if(locifupper+k>=26){
                    return str2[abs((26-locifupper)-k)];
                }else{
                    return str2[locifupper+k];
                }
            }
            locifupper++;
        }
    }else{
        for(int i =0;i<=strlen(str1);i++){
            if(letter == str1[i]){
                if(lociflower+k>=26){
                    return str1[abs((26-lociflower)-k)];
                    
                }else{
                    return str1[lociflower+k];
                }
            }
            lociflower++;
        }

    }
}