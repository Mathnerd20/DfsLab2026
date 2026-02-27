#include<stdio.h>

void InsertionSort(int[], int);

int main()
{
	int n;
	printf("Enter number of elements:");
	scanf("%d", &n);
	int arr[n];
	printf("Enter elements:\n");
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	InsertionSort(arr, n);
	printf("Sorted elements:\n");
	for(int i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
		if(i != n-1)
			printf(" ");
		else
			printf("\n");
	}
}

void InsertionSort(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = i;(j>0) && (arr[j] < arr[j-1]); j--)
		{
			int temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;
		}
	}
}
