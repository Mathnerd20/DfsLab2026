#include<stdio.h>

int BinarySearch(int[], int, int, int);

int main()
{
	int n;
	printf("Enter number of elements:");
	scanf("%d", &n);
	int arr[n];
	printf("Enter n elements:");
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("Enter an element to search:");
	int k;
	scanf("%d", &k);
	int index = BinarySearch(arr, 0, n-1, k);
	if(index == -1)
		printf("Element not found\n");
	else
		printf("Element found at index %d\n", index);
}

int BinarySearch(int arr[], int f, int l, int k)
{
	if(f > l)
		return -1;
	int m = (f+l)/2;
	if(arr[m] == k)
		return m;
	else if(arr[m] < k)
		return BinarySearch(arr, m+1, l, k);
	else if(arr[m] > k)
		return BinarySearch(arr, f, m-1, k);
}
