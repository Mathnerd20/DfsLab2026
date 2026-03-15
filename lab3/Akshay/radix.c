#include<stdio.h>
//Done at home, didn't do in lab
int dig(int);
int main()
{
    int n;
    printf("Enter no.of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: \n");
    int max = 0;
    for(int i = 0; i < n; i++)
    {
	scanf("%d", &a[i]);
	if(a[i] > max)
	{
	    max = a[i];
	}
    }
    int tab[n][10];
    int ten = 10;
    for(int i = 1; i <= dig(max); i++)
    {
	for(int i = 0; i < n; i++)
	{
	    for(int j = 0; j < 10; j++)
	    {
			    tab[i][j] = 0; 
	    }
	}
	for(int j = 0; j < n; j++)
	{
	    int k = 0;
	    int num = (a[j] % ten)/(ten/10);
	    while(tab[k][num] != 0)
	    {
		k++;
	    }
	    tab[k][num] = a[j];
	}
	int k = 0;
	for(int j = 0; j < 10; j++)
	{
	    int row = 0;
	    while(tab[row][j] != 0 && k < n)
	    {
		a[k] = tab[row][j];
		row++;
		k++;
	    }
	}
	ten = ten * 10;
    }
    for(int i = 0; i < n; i++)
    {
	printf("%d ", a[i]); 
    }
}

int dig(int a)
{
    int d = 0;
    while(a > 0)
    {
	a = a/10;
	d++;
    }
    return d;
}
