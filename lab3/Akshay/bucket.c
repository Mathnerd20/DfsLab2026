//done at home
#include<stdio.h>
void swap(float *, float *);
int main()
{
    int n;
    scanf("%d", &n);
    float  a[n];
    for(int i = 0; i < n; i++)
    {
	scanf("%f", &a[i]);
    }
    float buck[10][n];
    for(int i = 0; i < 10; i++)
    {
	for(int j = 0; j < n; j++)
	{
	    buck[i][j] = 0;
	}
    }
    for(int i = 0; i < n; i++)
    {
	int row = a[i] * 10;
	int k = 0;
	while(buck[row][k] != 0 && k < n)
	{
	    k++;
	}
	buck[row][k] = a[i];
    }
    for(int i = 0; i < 10; i++)
    {
	for(int j = 0; j < n - 1; j++)
	{
	    int k = j + 1;
	    while(a[j-1] > a[j] && j > 0)
	    {
		swap(&a[j-1], &a[j]);
		j--;
	    }
	}
    }
    int cur = 0;
    for(int i = 0; i < 10; i++)
    {
	int j = 0;
	while(buck[i][j] != 0 && j < n)
	{
	    a[cur] = buck[i][j];
	    cur++;
	    j++;
	}
    }
    printf("Sorted Array is: \n");
    for(int i = 0; i < n; i++)
    {
	printf("%f ", a[i]);
    }
}

void swap(float *a, float *b)
{
    float k = *a;
    *a = *b;
    *b = k;
    return;
}

