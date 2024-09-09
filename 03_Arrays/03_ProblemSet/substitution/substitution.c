#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int validation(int argc , string argv[]);
int checkDuplicate(int argc , string argv[]);

int main(int argc , string argv[]){

    // function validating inline argument 
    if(validation(argc , argv)==1){
        return 1;
    }

    // funtion to evaluate if the key is 26 letters and contain all the letters .
    if(checkDuplicate(argc , argv) == 1){
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // assigning text to string  with both upper and lower case
    string upperAlphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowerAlphabets = "abcdefghijklmnopqrstuvwxyz";


    string key = argv[1];
    // key[strlen(argv[1])] = '\0';

    // taking input from user for plain text
    string plaintext = get_string("plaintext: ");
    char ciphertext[strlen(plaintext)];


    // outputting cipher text 
    for(int i = 0;i<strlen(plaintext);i++){
        if(islower(plaintext[i])){
            for(int j = 0 ; j<strlen(lowerAlphabets);j++){
                if(plaintext[i]==lowerAlphabets[j]){
                    ciphertext[i] = tolower(argv[1][j]);
                }
            }
        }
        else 
        if(isupper(plaintext[i])){
            for(int j = 0 ; j<strlen(upperAlphabets);j++){
                if(plaintext[i]==upperAlphabets[j]){
                    ciphertext[i] = toupper(argv[1][j]);
                }
            }
        }else{
            ciphertext[i]=plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)]='\0';


    // ciphertext[strlen(plaintext)] ='\0';
    printf("ciphertext: %s", ciphertext);
}

int validation(int argc , string argv[]){
    string subkey = argv[1];

    if(argc!=2){
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if(strlen(argv[1])!=26){
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else{

        for(int i=0;i<strlen(argv[1]);i++){
            if(!isalpha(argv[1][i])){
                printf("wrong key implementation \n");
                return 1;
            }
        }
        

    }
        return 0;
}

int checkDuplicate(int argc , string argv[]){
    string alphabets = "abcdefghijklmnopqrstuvwxyz\0";
    int alphabetscount = 0;

    // checking for everycharacter present
    for(int i = 0 ; i<strlen(alphabets);i++){
        for(int j=0;j<strlen(argv[1]);j++){

            if(alphabets[i]==tolower(argv[1][j])){
                alphabetscount++;
                break;
            }
        }
        
    }
    if(alphabetscount != strlen(argv[1])){
        printf("doubling not allowed %d , %d\n" , alphabetscount, strlen(argv[1]));
        return 1;
    }
    return 0;
}