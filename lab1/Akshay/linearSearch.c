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
	for(int i = 0; i < n; i++)
	{
		if(k == a[i])
		 {
			printf("Element is found at index %d\n", i);
			return 0;
		 }
	}
	printf("Element is not found"); 
}
