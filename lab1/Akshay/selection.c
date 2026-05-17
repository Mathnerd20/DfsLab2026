#include<stdio.h>

void selrec(int, int, int[]);
int listmin(int, int, int[]);

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

	selrec(0, n-1, a);

	for(int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

void selrec(int f, int n, int a[n])
{
	if(f < n)
	{
		int k;
		int min = listmin(f, n, a);
		k = a[f];
		a[f] = a[min];
		a[min] = k;
		selrec(f+1, n, a);
	}
	return;
}

int listmin(int f, int n, int a[n])
{
	int min = a[f];
	int index;
	for(int i = f; i <= n; i++)
	{
		if(min > a[i])
		{
			min = a[i];
			index = i;
		}
	}
	return index;
}
