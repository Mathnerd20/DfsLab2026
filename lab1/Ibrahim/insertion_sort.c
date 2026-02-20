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

    for(int i = 0;i<n;i++){
        int j= i;
        while(j>0 && (arr[j]<arr[j-1])){
            swap(arr,j,j-1);
            j--;
        }
    }

    printf("the sorted array : ");
    printarr(arr,n);
    printf("\n");0

    return 0;

}