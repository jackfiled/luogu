#include <cstdio>
#include <cstring>

// dp[i][j]
// i 当前栈中数字的数量
// j 当前输入的数字数量
int dp[20][20];

int main()
{
    int number;
    scanf("%d", &number);
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= number; i++)
    {
        // 设置dp的初始条件
        dp[i][0] = 1;
    }

    for (int j = 1;j <= number; j++)
    {
        for (int i = 0; i <= number - j; i++)
        {
            if (i >= 1)
            {
                dp[i][j] = dp[i - 1][j] + dp[i + 1][j - 1];
            }
            else
            {
                dp[i][j] = dp[i + 1][j - 1];
            }
        }
    }

    printf("%d\n", dp[0][number]);
    return 0;
}