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



int partition(int arr[],int low,int high){
    int pivot_item = arr[low];
    int right = high;
    int left = low;

    while(left < right){
        while(arr[left] <= pivot_item){
            left++;
        }

        while(arr[right] > pivot_item){
            right--;
        }
        if(left < right){
            swap(arr,left,right);
        }
    }

    arr[low] = arr[right];
    arr[right] = pivot_item;
    return right;
}
void quick_sort(int arr[],int low,int high){
    int pivot;
    if(high>low){
        pivot = partition(arr,low,high);
        quick_sort(arr,low,pivot-1);
        quick_sort(arr,pivot+1,high);
    }
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

    quick_sort(arr,0,n-1);
    printarr(arr,n);

    return 0;                         
}