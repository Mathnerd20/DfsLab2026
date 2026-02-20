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
        printf("The element is found at index %d\n",index);
    }
    else{
        printf("The element is not found in the array\n");
    }

    return 0;
}