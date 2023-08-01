#include <cstdio>

int main()
{
    int i, j, k;
    scanf("%d %d %d", &i, &j, &k);
    int result = 0;
    
    for (int m = 1; m <= 1000 / k; m++)
    {
        int a = m * i;
        int b = m * j;
        int c = m * k;

        if (b > 999 or c > 999)
        {
            break;
        }

        char used[10] = {0};

        for (int n = 0; n < 3; n++)
        {
            used[a % 10]++;
            a = a / 10;
        }

        for (int n = 0; n < 3; n++)
        {
            used[b % 10]++;
            b = b / 10;
        }

        for (int n = 0; n < 3; n++)
        {
            used[c % 10]++;
            c = c / 10;
        }

        bool flag = true;
        for (int i = 1; i <= 9; i++)
        {
            if (used[i] != 1)
            {
                flag = false;
            }
        }

        if (flag)
        {
            printf("%d %d %d\n", m * i, m * j, m * k);
            result++;
        }
    }

    if (result == 0)
    {
        printf("No!!!\n");
    }
    return 0;
}