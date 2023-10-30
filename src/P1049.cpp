#include <cstdio>
#include <cstring>
#define MAX(a, b) (a) > (b) ? (a) : (b)

int main()
{
    int V, number;
    scanf("%d%d", &V, &number);

    int values[number + 1];

    for (int i = 1; i <= number; i++)
    {
        scanf("%d", &values[i]);
    }

    int dp[number + 1][V + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= number; i++)
    {
        for (int j = V; j >= 0; j--)
        {
            if (j >= values[i])
            {
                dp[i][j] = MAX(dp[i - 1][j], dp[i - 1][j - values[i]] + values[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printf("%d\n", V - dp[number][V]);
    return 0;
}