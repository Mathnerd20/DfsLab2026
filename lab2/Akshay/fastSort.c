#include<stdio.h>
void mergesort(int, int, int , int []);
void merge(int, int, int, int, int, int []);
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
	int k;
	printf("Press \n 1 for Merge Sort \n 2 for Quick Sort \n");
	int s;
	scanf("%d", &s);
	switch(s)
	{
		case(1):
		mergesort(n, 0, n-1, a);
			break;
		case(2):
		quicksort(n, 0, n-1, a);
			break;
	}
	printf("The sorted list is: \n");
	for(int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
void mergesort(int n, int f, int l, int a[])
{
	if(f < l)
	{
		int m = (f+l)/2;
		mergesort(n,f,m,a);
		mergesort(n,m+1,l,a);
		merge(n,f,m,m+1,l,a);
	}
	return;
}
void merge(int n, int lf, int ll, int rf, int rl, int a[])
{
	int c[n];
	int lol = lf;
	int i = lf;
	while(lf <= ll && rf <= rl)
	{
		if(a[lf] < a[rf])
		{
			c[i] = a[lf];
			lf++;
		}
		else
		{
			c[i] = a[rf];
			rf++;
		}
		i++;
	}
	while(lf <= ll)
	{
		c[i] = a[lf];
		lf++;
		i++;
	}
	while(rf <= rl)
	{
		c[i] = a[rf];
		rf++;
		i++;
	}
	for(int i = lol; i <= rl;i++)
	{
		a[i] = c[i];
	}
	return;
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
	left = low + 1;
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
