#include<stdio.h>

int LinearSearch(int[], int, int);
int BinarySearch(int[], int, int, int);

int main()
{
	int n;
	printf("Enter number of elements:");
	scanf("%d", &n);
	int arr[n];
	printf("Enter n elements:\n");
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int k;
	printf("Enter an element to search:");
	scanf("%d", &k);
	int s;
	printf("Enter 1 for Linear search \nEnter 2 for Binary search\n");
	scanf("%d", &s);
	int i;
	switch(s)
	{
		case 1:
			i =  LinearSearch(arr, n, k);
			break;
		case 2:
			i = BinarySearch(arr, 0, n-1, k);
			break;
		default:
			printf("Invalid input");
			return 0;
	}
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

int BinarySearch(int arr[], int f, int l, int k)
{
	if(f > l)
		return -1;
	int m = (f+l)/2;
	if(arr[m] == k)
		return m;
	else if(arr[m] < k)
		BinarySearch(arr, m+1, l, k);
	else if(arr[m] > k)
		BinarySearch(arr, f, m-1, k);
}
