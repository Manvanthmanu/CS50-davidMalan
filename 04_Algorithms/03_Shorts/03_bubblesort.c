#include <stdio.h>


int main(){

    int arr1[] = {22,10,23,17,1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int length = sizeof(arr1)/sizeof(arr1[0]);
    printf("%d\n",length);
    int rep = 1;

    while(rep){
        rep = 0;

        for(int i=0;i<length-1;i++){
            if(arr1[i]>arr1[i+1]){
                int temp = arr1[i];
                arr1[i]=arr1[i+1];
                arr1[i+1]= temp;
                rep++;
            }
        }
    }
    
    for(int i=0;i<length;i++){
        printf("%d ",arr1[i]);
    }


    return 0;
}