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

    merge_sort(arr,0,n-1);
    printarr(arr,n);

    return 0;
}