#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>
#include <math.h>




int letterCount(string Text, int strLength);
int wordCount(string Text, int strLength);
int sentanceCount(string Text, int strLength);
float algorithm(float L , float S);

int main(void){

    // input for sentance get string;
    string Text = get_string("Text: ");
    int strLength = strlen(Text);

    // total length to depict average of all per 100 words 

    // function to calculate letters per 100 words ;
    int totalL = letterCount(Text,strLength);

    // function to calculate word per 100 words ;
    int totalW =  wordCount(Text ,strLength);


    // function to calculate sentance per 100 words ;
    int totalS = sentanceCount(Text,strLength);



    // averaging numbers to 100;
    float L = ((float) totalL / totalW) * 100; // average letters per 100 words
    float S = ((float) totalS / totalW) * 100; // average sentences per 100 words

    
    printf("%i ,%.2f ,%.2f" , totalW,L,S);


    // algorithm with rounding { simply finding x }
    int index = round(algorithm(L  , S));
    printf("%i\n" , index);

    // minimum and maximum with output grade ;
    if(index<=1){
        printf("Before Grade 1\n");
    }else if(index>=16){
        printf("Grade 16+\n");
    }else{
        printf("Grade %i\n" , index);
    }

}


// letter count function
int letterCount(string Text , int strLength){
    int letterCountnum = 0;
    for(int i = 0 ;i<strLength ;i++){
        if(isalpha(Text[i])){
            letterCountnum++;
        }
    }
    return letterCountnum;
}

int wordCount(string Text ,int strLength){
    int wordCountnum = 1;
    for(int i = 0 ;i<strLength ;i++){
        if(Text[i]==' '){
            wordCountnum++;
        }
    }
    return wordCountnum;

}

int sentanceCount(string Text, int strLength){

    int sentanceCountnum = 0;
    for(int i = 0 ;i<strLength ;i++){
        if(Text[i]=='!' || Text[i]=='?' || Text[i]=='.'){
            sentanceCountnum++;
        }
    }
    return sentanceCountnum;

}

float algorithm(float L  , float S){
    float algovalue =  0.0588 * L - 0.296 * S - 15.8 ;
    return algovalue;
}