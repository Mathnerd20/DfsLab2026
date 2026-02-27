#include<stdio.h>

int LinearSearch(int[], int, int);

int main()
{
	int n;
	printf("Enter number of elements:");
	scanf("%d", &n);
	int arr[n];
	printf("Enter n elements:\n");
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("Enter an element to search:");
	int k;
	scanf("%d", &k);
	int i =  LinearSearch(arr, n, k);
	if(i == -1)
		printf("Element not found\n");
	else
		printf("Element found at index %d\n", i);
}

int LinearSearch(int arr[], int n, int k)
{
	for(int i = 0; i < n; i++)
		if(arr[i] == k)
			return i;
	return -1;
}
