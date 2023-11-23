#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> sum(n + 1, 0);

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0x7fffffff));

    for (int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);

        sum[i] = sum[i - 1] + t;
        dp[i][i] = 0;
    }

    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n -len + 1; i++)
        {
            int j = i + len - 1;

            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    }

    printf("%d\n", dp[1][n]);

    return 0;
}