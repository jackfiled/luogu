#include <cstdio>
#include <cmath>
#include <cstring>

int result[1001], a[1001], middle[1001];

int main()
{
    int number;
    scanf("%d", &number);

    // 2^p = (10^(lg2))^p
    // = 10^(plg2)
    int time = log10(2) * number + 1;
    printf("%d\n", time);

    memset(result, 0, sizeof(result));
    memset(a, 0, sizeof(a));
    result[1] = 1;
    a[1] = 2;

    while (number != 0)
    {
        if ((number & 1) == 1)
        {
            // result = result * a;
            memset(middle, 0, sizeof(middle));
            for (int i = 1; i <= 500; i++)
            {
                for (int j = 1; j <= 500; j++)
                {
                    middle[i + j - 1] = a[i] * result[j] + middle[i + j - 1];
                }
            }
            for (int i = 1; i <= 500; i++)
            {
                // 只有前500位重要
                // 处理进位
                middle[i + 1] = middle[i + 1] + middle[i] / 10;
                middle[i] = middle[i] % 10;
            }
            memcpy(result, middle, sizeof(middle));
        }

        number = number >> 1;

        // a = a^2
        memset(middle, 0, sizeof(middle));
        for (int i = 1; i <= 500; i++)
        {
            for (int j = 1; j <= 500; j++)
            {
                middle[i + j - 1] = a[i] * a[j] + middle[i + j - 1];
            }
        }
        for (int i = 1; i <= 500; i++)
        {
            // 只有前500位重要
            // 处理进位
            middle[i + 1] = middle[i + 1] + middle[i] / 10;
            middle[i] = middle[i] % 10;
        }
        memcpy(a, middle, sizeof(middle));
    }

    result[1] = result[1] - 1;

    for (int i = 499; i >= 0; i--)
    {
        if (i != 500 and i % 50 == 0)
        {
            printf("%d\n", result[i + 1]);
        }
        else
        {
            printf("%d", result[i + 1]);
        }
    }

    return 0;
}