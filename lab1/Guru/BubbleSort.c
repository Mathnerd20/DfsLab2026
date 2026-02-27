#include<stdio.h>

void BubbleSort(int[], int);

int main()
{
	int n;
	printf("Enter number of elements:");
	scanf("%d", &n);
	int arr[n];
	printf("Enter elements:\n");
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	BubbleSort(arr, n);
	printf("Sorted elements:\n");
	for(int i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
		if(i != n-1)
			printf(" ");
		else
			printf("\n");
	}
}

void BubbleSort(int arr[], int n)
{
	for(int i = 0; i < n-1; i++)
	{
		for(int j = 0; j < n-i-1; j++)
		{
				if(arr[j] > arr[j+1])
				{
					int temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
		}
	}
}
