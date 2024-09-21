#include <stdio.h>

int main(){

    int arr1[] = {22,10,23,17,1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int length = sizeof(arr1)/sizeof(arr1[0]);
    printf("%d\n",length);

    for(int i = 0;i<length-1;i++){
        for(int j = i+1;j<length;j++){
            if(arr1[i]>arr1[j]){
                int temp=arr1[i];
                arr1[i]=arr1[j];
                arr1[j]=temp;
                // printf("%d - %d\n",arr1[i],arr1[j]);
            }
        }
    }
    
    for(int i=0;i<length;i++){
        printf("%d ",arr1[i]);
    }

    return 0;
}