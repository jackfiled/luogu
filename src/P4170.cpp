#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    string board;
    cin >> board;
    int n = board.length();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0x7fffffff));
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; ++len)
    {
        for (int l = 1, r = l + len - 1; r <= n; ++l, ++r)
        {
            if (board[l - 1] == board[r - 1])
            {
                dp[l][r] = min(dp[l - 1][r], dp[l][r - 1]);
            }
            else
            {
                for (int k = l; k < r; ++k)
                {
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
                }
            }
        }
    }

    printf("%d\n", dp[1][n]);
    return 0;
}