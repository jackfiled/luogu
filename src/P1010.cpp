#include <cstdio>
#include <cmath>

void factor(int x)
{
    for (int i = 15; i >= 0; i--)
    {
        if (pow(2, i) <= x)
        {
            if (i == 0)
            {
                printf("2(0)");
            }
            else if (i == 1)
            {
                printf("2");
            }
            else
            {
                // 继续分解因数
                printf("2(");
                factor(i);
                printf(")");
            }

            x = x - pow(2, i);
            if (x != 0)
            {
                // 说明还没完
                printf("+");
            }
        }
    }
}

int main()
{
    int number;
    scanf("%d", &number);

    factor(number);
    printf("\n");

    return 0;
}