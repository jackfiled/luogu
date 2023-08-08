#include <cstdio>
#include <cstring>

int f[1001] = {0};

int main()
{
    int number;
    scanf("%d", &number);

    f[1] = 1;
    f[2] = 2;

    for (int i = 3; i <= number; i++)
    {
        // 只有自己一个数
        f[i] = 1;
        for (int j = 1; j <= i / 2; j++)
        {
            f[i] = f[i] + f[j];
        }
    }

    printf("%d\n", f[number]);
    return 0;
}