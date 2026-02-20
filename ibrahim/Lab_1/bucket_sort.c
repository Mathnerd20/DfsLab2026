#include<stdio.h>

int main(){

    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);

    float arr[n];
    printf("Please enter the elements of the array: \n");

    for(int i = 0;i<n;i++){
        printf("Enter the element(decimal number betweem 0 - 0.99) No %d : ",i+1);
        scanf("%f",&arr[i]);
        if((arr[i] < 0) || (arr[i] >= 1))
        {
            printf("The element is not in required range\n");
            i--;
        }
    }
    float bucket[10][n];
    int bucket_index[10] = {0,0,0,0,0,0,0,0,0,0};

    int index;

    for(int i = 0;i < n;i++){
        index = arr[i]*10;
        bucket[index][bucket_index[index]] = arr[i];
        bucket_index[index]++;
    }

    for(int i = 0;i < 10;i++){
        float temp;
        for(int k = 0;k<bucket_index[i];k++){
            int j= k;
            while(j>0 && (bucket[i][j]< bucket[i][j-1])){
                temp = bucket[i][j];
                bucket[i][j] = bucket[i][j-1];
                bucket[i][j-1] = temp;
                j--;
            }
        }
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0;j < bucket_index[i];j++){
            printf("%f ",bucket[i][j]);
        }
    }


    return 0;
}