#include <stdio.h>
#include <string.h>

int main(){

   char calls[20];
    
    // Limit input to 19 characters to leave room for null terminator
    scanf("%19s", calls);
    
    // Print each character of the string
    for(int i = 0; i < strlen(calls); i++) {
        printf("%c", calls[i]);
    }
}