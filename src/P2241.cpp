#include <cstdio>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    long long sqrt = 0, rect = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j)
            {
                sqrt += (n - i) * (m - j);
            }
            else
            {
                rect += (n - i) * (m - j);
            }
        }
    }

    printf("%lld %lld\n", sqrt, rect);
    return 0;
}