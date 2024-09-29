#include <stdio.h>
// void merge

void merge(int arr1[],int low ,int mid ,int high){

    int n1=mid-low+1;
    int n2=high-mid;

    int leftarr[n1],rightarr[n2];

    for(int i=0;i<n1;i++){
        leftarr[i]=arr1[low+i];
    }
    for(int i=0;i<n2;i++){
        rightarr[i]=arr1[mid+1+i];
    }

    // Merge the temporary arrays back into arr[left..right]

    int i=0,j=0,k=low;
    while(i<n1 && j <n2){
        if(leftarr[i]<=rightarr[j]){
            arr1[k]=leftarr[i];
            i++;
        }else{
            arr1[k]=rightarr[j];
            j++;
        }
        k++;
    }
      while (i < n1) {
        arr1[k] = leftarr[i];
        i++;
        k++;
    }

    while(j<n2){
        arr1[k]=rightarr[j];
        j++;
        k++;
    }




}
void mergesort(int arr1[], int low , int high){
    if(low<high){
        int mid = low+(high-low)/2;

        mergesort(arr1,low,mid);
        mergesort(arr1,mid+1,high);

        merge(arr1,low,mid, high);
    }


}

int main(){

    int arr1[] = {22,10,23,17,1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int length = sizeof(arr1)/sizeof(arr1[0]);

    
    printf("Given array is: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    mergesort(arr1, 0, length - 1);

    printf("Sorted array is: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    return 0;
}