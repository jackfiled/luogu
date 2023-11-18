#include <cstdio>
#include <vector>
#define MOD 1000000007

using namespace std;

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    char a[n + 1];
    char b[m + 1];
    scanf("%s", a + 1);
    scanf("%s", b + 1);

    vector<vector<vector<vector<int>>>> dp(2,
        vector<vector<vector<int>>>(m + 1,
            vector<vector<int>>(k + 1,
                vector<int>(2))));

    // dp[i][j][p][0/1] 表示匹配到A的i位，匹配到B的j位，划分为p个字串，是否选择第i个字符
    dp[0][0][0][0] = 1;
    dp[1][0][0][0] = 1;

    // 压缩dp数组的第一维
    int now = 1;
    for (int i = 1; i <= n; i++)
    {
        int last;
        if (now == 1)
        {
            last = 0;
        }
        else
        {
            last = 1;
        }

        for (int j = 1; j <= m; j++)
        {
            for (int l = 1; l <= k; l++)
            {

                if (a[i] == b[j])
                {
                    dp[now][j][l][0] = (dp[last][j][l][0] + dp[last][j][l][1]) % MOD;

                    dp[now][j][l][1] = (dp[last][j - 1][l][1] + (dp[last][j - 1][l - 1][0] + dp[last][j - 1][l - 1][1]) % MOD) % MOD;
                }
                else
                {
                    dp[now][j][l][0] = (dp[last][j][l][0] + dp[last][j][l][1]) % MOD;

                    dp[now][j][l][1] = 0;
                }
            }
        }

        now = last;
    }

    printf("%d\n", (dp[n & 1][m][k][0] + dp[n & 1][m][k][1]) % MOD);
    return 0;
}