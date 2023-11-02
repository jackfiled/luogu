#include <cstdio>
#include <cstring>

#define MIN(a, b) (a) < (b) ? (a) : (b)

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int limits[n + 1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &limits[i]);
    }

    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            int max = MIN(j, limits[i]);
            for (int k = 0; k <= max; k++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % 1000007;
            }
        }
    }

    printf("%d\n", dp[n][m]);
    return 0;
}