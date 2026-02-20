#include<stdio.h>

void printarr(int arr[],int n){
    for(int i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }
}

void swap(int arr[],int a,int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int main(){

    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);

    int arr[n];
    printf("Please enter the elements of the array: \n");

    for(int i = 0;i<n;i++){
        printf("Enter the element No %d : ",i+1);
        scanf("%d",&arr[i]);
    }

    int small;
    for(int i = 0;i < n;i++){
        small = i;
        for(int j = i;j < n;j++){
            if(arr[small] > arr[j]){
                small = j;
            }
        }
        swap(arr,i,small);
    }
    printf("the sorted array : ");
    printarr(arr,n);
    printf("\n");
    
    return 0;
}