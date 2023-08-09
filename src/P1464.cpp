#include <cstdio>
#include <cstring>

long long wResult[21][21][21];

long long w(long long a, long long b, long long c)
{
    if (a <= 0 or b <= 0 or c <= 0)
    {
        return 1;
    }

    if (a > 20 or b > 20 or c > 20)
    {
        return w(20, 20, 20);
    }

    if (wResult[a][b][c] != 0)
    {
        return wResult[a][b][c];
    }

    if (a < b and b < c)
    {
        wResult[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    else
    {
        wResult[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) 
            - w(a - 1, b - 1, c - 1);
    }

    return wResult[a][b][c];
}

int main()
{
    memset(wResult, 0, sizeof(wResult));

    while (true)
    {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        if (a == -1 and b == -1 and c == -1)
        {
            break;
        }

        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
    }

    return 0;
}