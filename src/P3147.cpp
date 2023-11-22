#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector<vector<int>> dp(60, vector<int>(n + 2, 0));

    for (int i = 1; i <= n; ++i)
    {
        int t;
        scanf("%d", &t);

        dp[t][i] = i + 1;
    }

    int result = 0;
    for (int i = 2; i <= 58; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dp[i][j] == 0)
            {
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
            }

            if (dp[i][j] != 0)
            {
                result = i;
            }
        }
    }

    printf("%d\n", result);
    return 0;
}