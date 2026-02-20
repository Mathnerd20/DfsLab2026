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

void merge(int arr[],int left_first,int left_last,int right_first,int right_last){
    int savefirst = left_first;
    int temp_arr[right_last+1];
    int index = left_first;

    while((left_first <= left_last) && (right_first <= right_last)){
        
        if(arr[left_first] < arr[right_first]){
            temp_arr[index] = arr[left_first];
            left_first++;
        }
        else{
            temp_arr[index] = arr[right_first];
            right_first++;
        }
        index++;
    }

    while(left_first<=left_last){
        temp_arr[index] = arr[left_first];
        index++;
        left_first++;
    }

    while(right_first <= right_last){
        temp_arr[index] = arr[right_first];
        index++;
        right_first++;
    }

    for(int i = savefirst; i <= right_last; i++){
        arr[i] = temp_arr[i];
    }
}

void merge_sort(int arr[],int first,int last){

    int middle;
    if(first<last){
        middle = (first+last)/2;
        merge_sort(arr,first,middle);
        merge_sort(arr,middle+1,last);
        merge(arr,first,middle,middle+1,last);
    }
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

void bubble_sort(int arr[],int n){

     for(int i = 0;i < n;i++){
        for(int j = 0;j<n-1-i;j++){
            if(arr[j] > arr[j+1]){
                swap(arr,j,j+1);
            }
        }
    }
}

void selection_sort(int arr[],int n){

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
}

void insertion_sort(int arr[],int n){

    for(int i = 0;i<n;i++){
        int j= i;
        while(j>0 && (arr[j]<arr[j-1])){
            swap(arr,j,j-1);
            j--;
        }
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

    int option;
    printf("Enter the sort you want to use: \n1.insertion sort\n2.selection sort\n3.bubble sort\n4.merge sort\n5.quick sort\n");
    scanf("%d",&option);
    switch(option){
        case 1:
            insertion_sort(arr,n);
        case 2:
            selection_sort(arr,n);
        case 3:
            bubble_sort(arr,n);
        case 4:
            merge_sort(arr,0,n-1);
        case 5:
            quick_sort(arr,0,n-1);
            
    }
    printarr(arr,n);

    return 0;
}