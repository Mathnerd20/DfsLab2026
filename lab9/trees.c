# include <stdio.h>

int pwr (int a , int b)
{
    if (b == 0) return 1;
    int c = a;
    for (int i = 1 ; i <= b-1 ; i++) a = c*a;
    return a;
}

float lg (float x)
{
    int n = 0;
    while (x > 1)
    {
        x /= 2.0;
        n++;
    }
    return n;
}

int main ()
{
    int n ; printf("Enter the number of the nodes : ") ; scanf("%d", &n);

    int tree[n];

    for (int i = 0 ; i < n ; i++)
    {
        printf("Enter the %dth element : ", i+1);
        scanf("%d", &tree[i]);
    }

    int j = 0;
    float t = n+1;
    for (int i = 0 ; i <= lg(t)-1 ; i++)
    {
        printf("Level %d : ", i);
        while (j < (pwr(2 , i+1) - 1) && j < n)
        {
            printf("%d ", tree[j]);
            j++;
        }
        printf("\n");
    }
}