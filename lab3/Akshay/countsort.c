#include<stdio.h>
int maxlist(int, int[]);

int main()
{
	int n;
	printf("Enter number of integers in array: ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++)
	{
		printf("Enter element number %d: ", i+1);
		scanf("%d", &a[i]);
	}
	int k = maxlist(n,a);
	int b[k];
	for(int i = 0; i < k; i++)
	{
		b[i] = 0;
	}
	for(int i = 0; i < n; i++)
	{
		b[a[i]-1]++;
	}
	printf("The sorted list is: \n");
	for(int i = 0; i < k; i++)
	{
		for(int j = 1 ; j <= b[i]; j++)
		{
			printf("%d ", i+1);
		}
	}
}

int maxlist(int n, int a[])
{
	int max = a[0];
	for(int j = 1; j < n; j++)
	{
		if(max < a[j])
		{
			max = a[j];
		}
	}
	return max;
}
