#include<stdio.h>

void sort(int arr[],int div,int n){
    int count[10];
    int max = 10;
    for(int i = 0;i<max;i++){
        count[i] = 0;
    }

    for(int i = 0;i < n;i++){
        count[(arr[i]%div)/(div/10)]++;
    }

    for(int i = 1; i<max;i++){
        count[i] = count[i] + count[i-1];
    }

    int a,b;

    int sorted[n];
    for(int  i = n-1;i >= 0;i--){
        a = arr[i];
        b = count[(arr[i]%div)/(div/10)]-1;
        sorted[b] = a;
        count[(arr[i]%div)/(div/10)]--;
    }
    for(int i = 0; i < n;i++){
        arr[i] = sorted[i];
    }
}

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

    int digit = 0;
    while(max != 0){
        max = max/10;
        digit++;
    }

    int div = 10;

    while(digit != 0){
        sort(arr,div,n);
        div = div*10;
        digit--;
    }

    for(int i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}