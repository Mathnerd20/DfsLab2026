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
	for(int i = 0; i < n-1; i++)
	{
		int j = i + 1;
		while(j > 0 && a[j] < a[j-1])
		{
			int k = a[j-1];
			a[j-1] = a[j];
			a[j] = k;
			j--;
		}
	}
	for(int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
