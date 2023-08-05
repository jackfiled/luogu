#include <cstdio>

int used[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
    int a[2001] = {6}, number, result = 0;
    scanf("%d", &number);

    for (int i = 1; i <= 2000; i++)
    {
        int j = i;
        while(j >= 1)
        {
            a[i] = a[i] + used[j % 10];
            j = j / 10;
        }
    }

    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            if (a[i] + a[j] + a[i + j] + 4 == number)
            {
                result++;
            }
        }
    }

    printf("%d\n", result);
    return 0;
}