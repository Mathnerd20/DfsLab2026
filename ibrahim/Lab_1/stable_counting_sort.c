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

    for(int i = 1; i<max+1;i++){
        count[i] = count[i] + count[i-1];
    }

    int a,b;

    int sorted[n];
    for(int  i = n-1;i >= 0;i--){
        a = arr[i];
        b = count[a]-1;
        sorted[b] = a;
        count[a]--;

    }
    for(int i = 0;i < n; i++){
        printf("%d ",sorted[i]);
    }
    return 0;
}