#include<stdio.h>
int linear(int, int, int[]);
int binary(int, int, int, int []);
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
	printf("Enter the number to be searched: ");
	scanf("%d", &k);
	printf("Press 1 for Linear Search, 2 for Binary search");
	printf("\nNote: Elements should be in increasing order for binary search\n"); 
	int s;
	scanf("%d", &s);
	switch(s)
	{
		case(1):
			if(linear(k, n, a) != -1)
			{
				printf("Element is found at index %d\n", linear(k, n, a));
			}
			else
			{
				printf("Element is not found"); 
			}
			break;
		case(2):
			if(binary(k, 0, n-1, a) != -1)
			{
				printf("Element is found at index %d\n", binary(k, 0, n-1, a));
			}
			else
			{
				printf("Element is not found"); 
			}
			break;
	}
}
int linear(int k, int n, int a[n])
{
	for(int i = 0; i < n; i++)
	{
		if(k == a[i])
		 {
			 return i;
		 }
	}
	return -1;
}

int binary(int k, int f, int n, int a[n])
{
	int i = (f+n)/2;
	if(f > n)
	{
		return -1;
	}
	if(a[i] == k)
	{
		return i;
	}
	else if(a[i] > k)
	{
		binary(k, i+1, n, a); 
	}
	else
	{
		binary(k, f, i-1, a); 
	}
}
