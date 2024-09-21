#include <stdio.h>

int binarySearch(int arr1[],int target,int low , int high){
    if(low>high){
        return -1;
    }

    int mid = (low+high) /2;

    if(arr1[mid]==target){
        printf("digit found\n");
        return mid;
    }
    else if(arr1[mid]>target){
        return binarySearch(arr1,target,low,mid-1);
    }else{
        return binarySearch(arr1,target,mid+1,high);
    }
}

int main(){
    const int length = 10;
    int arr1[]={1,2,3,4,5,6,7,8,9,10};

    int digit = 7;

    printf("%d\n", binarySearch(arr1,digit,0,9));

    

    
    return 0;
}