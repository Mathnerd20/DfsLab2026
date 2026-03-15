#include<stdio.h>
void quicksort(int, int, int, int[]);
int partition(int, int, int, int[]);
int main()
{
	int n;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++)
	{
		printf("Enter element number %d: ", i+1);
		scanf("%d", &a[i]);
	}
	quicksort(n, 0, n-1, a);
	for(int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
void quicksort(int n, int low, int high, int a[])
{
	int pivot;
	if(high > low)
	{
		pivot = partition(n, low, high, a);
		quicksort(n, low, pivot - 1, a);
		quicksort(n, pivot + 1, high, a);
	}
	return;
}
int partition(int n, int low, int high, int a[])
{
	int left, right;
	int pivot = a[low];
	left = low;
	right = high;
	while(left < right)
	{
		while(a[left] <= pivot)
		{
			left++;
		}
		while(a[right] > pivot)
		{
			right--;
		}
		if(left < right)
		{
			int k = a[left];
			a[left] = a[right];
			a[right] = k;
		}
	}
	a[low] = a[right];
	a[right] = pivot;
	return right;
}
