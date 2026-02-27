#include<stdio.h>

void SelectionSort(int[], int, int);

int main()
{
	int n;
	printf("Enter number of elements:");
	scanf("%d", &n);
	int arr[n];
	printf("Enter elements:\n");
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	SelectionSort(arr, n, 0);
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

void SelectionSort(int arr[], int n, int f)
{
	if(f == n-1)
		return;
	int min = arr[f];
	int j = f;
	for(int i = f+1; i < n; i++)
		if(arr[i] < min)
		{
			min = arr[i];
			j = i;
		}
	arr[j] = arr[f];
	arr[f] = min;
	SelectionSort(arr, n, f+1);	
}
