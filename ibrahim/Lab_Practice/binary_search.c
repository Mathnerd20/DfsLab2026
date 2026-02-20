#include<stdio.h>

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
        printf("The element is found at index %d",mid);
    }
    else{
        printf("The element is not found in the array \n");
    }

    return 0;
}