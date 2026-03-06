#include<stdio.h>
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
	if(binary(k, 0, n-1, a) != -1)
	{
		printf("Element is found at index %d\n", binary(k, 0, n-1, a));
	}
	else
	{
		printf("Element is not found"); 
	}
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
