#include<stdio.h>
void selrec(int, int, int[]);
/*void swap(int a, int b)
{
	int k = a;
	a = b;
	b = k;
}*/
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
		k = a[f];
		a[f] = a[listmin(f,n,a)];
		a[listmin(f,n,a)] = k;
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
