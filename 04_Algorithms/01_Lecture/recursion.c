#include <stdio.h>
#include <cs50.h>

void draw(int n);
int main(){

    int height  = get_int("Height: ");
    draw(height);
    return 0;
}

void draw(int n){
    // if nothing to draw
    if(n<=0){
        return;
    }

    // print pyramid of height n-1
    draw(n-1);

    for(int i =0 ; i<n;i++){
        printf("#");
    }
    printf("\n");
}