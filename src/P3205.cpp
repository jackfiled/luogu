#include <cstdio>
#include <vector>

#define MOD 19650827

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int array[n + 1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &array[i]);
    }

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));

    for (int i = 1; i <=n; ++i)
    {
        dp[i][i][0] = 1;
    }

    for (int len = 1; len <= n; ++len)
    {
        for (int l = 1, r = l + len; r <= n; ++l, ++r)
        {
            if (array[l] < array[l + 1])
            {
                dp[l][r][0] += dp[l + 1][r][0];
            }

            if (array[l] < array[r])
            {
                dp[l][r][0] += dp[l + 1][r][1];
            }

            if (array[r] > array[l])
            {
                dp[l][r][1] += dp[l][r - 1][0];
            }

            if (array[r] > array[r - 1])
            {
                dp[l][r][1] += dp[l][r - 1][1];
            }

            dp[l][r][0] %= MOD;
            dp[l][r][1] %= MOD;
        }
    }

    printf("%d\n", (dp[1][n][0] + dp[1][n][1]) % MOD);
    return 0;
}