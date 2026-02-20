#include<stdio.h>

int binary_search(int arr[],int n,int key){

    int left = 0;
    int right = n-1;
    int mid;
    int found = 0;

    while(left <= right){
        mid = (left+right)/2;
        if(arr[mid] == key){
            found = 1;
            break;
        }
        else if(arr[mid] < key){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }  
    }

    if(found == 1){
        return mid;
    }
    else{
        return -1;
    }
}

int linear_search(int arr[],int n,int key){

    int found = 0;
    int index;

    for(int i = 0;i < n;i++){
        if(key == arr[i]){
            found = 1;
            index = i;
            break;
        }
    }

    if(found == 1){
        return index;
    }
    else{
        return -1;
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

    int key;
    printf("Enter the element you want to search : ");
    scanf("%d",&key);

    int option;
    printf("choose option : \n 1.)array is sorted\n 2.)array is not sorted\n");
    scanf("%d",&option);

    int result;
    switch(option){
        case 1:
            result = binary_search(arr,n,key);
        case 2:
            result = linear_search(arr,n,key);
}

    if(result == -1){
        printf("element is not found in the array\n");
    }
    else{
        printf("The element is found at index %d\n",result);
    }

    return 0;

}