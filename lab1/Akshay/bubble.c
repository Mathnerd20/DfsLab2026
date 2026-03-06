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
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n-i-1; j++)
		{
			if(a[j] > a[j+1])
			{
				int k = a[j];
				a[j] = a[j+1];
				a[j+1] = k;
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
