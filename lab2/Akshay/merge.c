#include<stdio.h>
void mergesort(int, int, int , int []);
void merge(int, int, int, int, int, int []);
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
	mergesort(n , 0, n-1, a);
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
