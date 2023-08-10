#include <cstdio>
#include <cstring>

// dp[i][j]
// i表示前i中菜品
// j 表示金额
// dp[i][j] = dp[i - 1][j] + dp[i][j - prices[i]]
int dp[101][10001];

int main()
{
    int number, money;
    scanf("%d %d", &number, &money);
    int prices[number];
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &prices[i]);
    }

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 101; i++)
    {
        // 考虑 有一菜恰好为j的情况
        dp[i][0] = 1;
    }

    for (int i = 1; i <= number; i++)
    {
        for (int j = 1; j <= money; j++)
        {
            dp[i][j] += dp[i - 1][j];
            if (j >= prices[i - 1])
            {
                dp[i][j] += dp[i - 1][j - prices[i - 1]];
            }
        }
    }

    printf("%d\n", dp[number][money]);

    return 0;
}