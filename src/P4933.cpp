#include <cstdio>
#include <vector>

#define LENGTH 20000
#define MOD 998244353

int main()
{
    int n;
    scanf("%d", &n);

    int towers[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &towers[i]);
    }

    // 枚举公差
    // 以i结尾公差为j的等差数列个数
    std::vector<std::vector<int>> dp(n, std::vector<int>(LENGTH * 2 + 1, 0));
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        result++;

        for (int j = i - 1; j >= 0; j--)
        {
            int delta = towers[i] - towers[j] + LENGTH;

            dp[i][delta] = dp[i][delta] + dp[j][delta] + 1;
            dp[i][delta] %= MOD;

            // 注意这里增加的新增的个数
            result = result + dp[j][delta] + 1;
            result = result % MOD;
        }
    }

    printf("%d\n", result);
    return 0;
}