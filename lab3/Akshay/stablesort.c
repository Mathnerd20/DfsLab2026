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
	int b[n][k];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < k; j++)
		{
			b[i][j] = 0;
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(b[j][a[i]-1] == 0)
			{
				b[j][a[i]-1]++;
				break;
			}
		}
	}
	printf("The sorted list is: \n");
	for(int i = 0; i < k; i++)
	{
		int j = 0;
		while(b[j][i] != 0)
		{
			printf("%d ", i + 1);
			j++;
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
