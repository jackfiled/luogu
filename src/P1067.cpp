#include <cstdio>

// 下面这种情况没有考虑
// 1
// 0 1
// +1

int main()
{
    int number;
    scanf("%d", &number);

    for (int i = number; i >= 0; i--)
    {
        int factor;
        scanf("%d", &factor);

        if (factor == 0)
        {
            continue;
        }
        else if(factor > 0)
        {
            // 正数
            if (i == number)
            {
                // 不需要打出加号
                if (i == 0)
                {
                    printf("%d", factor);
                }
                else
                {
                    factor != 1 ? printf("%dx^%d", factor, i) : printf("x^%d", i);
                }
            }
            else if (i == 1)
            {
                factor != 1 ? printf("+%dx", factor) : printf("+x");
            }
            else if (i == 0)
            {
                printf("+%d", factor);
            }
            else
            {
                // 需要打出加号
                factor != 1 ? printf("+%dx^%d", factor, i) : printf("+x^%d", i);
            }
        }
        else
        {
            // 负数
            if (i == 0)
            {
                printf("%d", factor);
            }
            else if (i == 1)
            {
                factor != -1 ? printf("%dx", factor) : printf("-x");
            }
            else
            {
                factor != -1 ? printf("%dx^%d", factor, i) : printf("-x^%d", i);
            }
        }
    }
    printf("\n");
    return 0;
}