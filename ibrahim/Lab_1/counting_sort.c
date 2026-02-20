#include<stdio.h>

int main(){

    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);

    int arr[n];
    printf("Please enter the elements of the array: \n");

    for(int i = 0;i<n;i++){
        printf("Enter the element (natural number) No %d : ",i+1);
        scanf("%d",&arr[i]);
        if(arr[i] < 0)
        {
            printf("The element is not a natural number\n");
            i--;
        }
    }

    int max;
    max = arr[0];
    for(int i = 1;i<n;i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }

    int count[max+1];

    for(int i = 0;i<max+1;i++){
        count[i] = 0;
    }

    for(int i = 0;i < n;i++){
        count[arr[i]]++;
    }

    for(int i = 0;i <= max;i++)
    {
        for(int j = 0;j < count[i];j++){
            printf("%d ",i);
        }
    }


    return 0;
}