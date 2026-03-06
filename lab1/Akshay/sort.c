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
	int k;
	printf("Press \n 1 for Bubble Sort \n 2 for Selection sort \n 3 for insertion sort \n");
	int s;
	scanf("%d", &s);
	switch(s)
	{
		case(1):
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
			break;
		case(2):
			selrec(0, n-1, a);
			break;
		case(3):
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
			break;
	}
	printf("The sorted list is: \n");
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
