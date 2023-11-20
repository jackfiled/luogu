#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> scores(n + 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &scores[i]);
    }

    vector<int> cards(5, 0);
    for (int i = 1; i <= m; i++)
    {
        int t;
        scanf("%d", &t);
        cards[t]++;
    }

    vector<vector<vector<vector<int>>>> dp(41, 
        vector<vector<vector<int>>>(41,
            vector<vector<int>>(41, 
                vector<int>(41, 0))));

    dp[0][0][0][0] = scores[1];
    
    for (int a = 0; a <= cards[1]; a++)
    {
        for (int b = 0; b <= cards[2]; b++)
        {
            for (int c = 0; c <= cards[3]; c++)
            {
                for (int d = 0; d <= cards[4]; d++)
                {
                    int target = 1 + a + b * 2 + c * 3 + d * 4;
                    if (a != 0)
                    {
                        dp[a][b][c][d] = max(dp[a][b][c][d], dp[a - 1][b][c][d] + scores[target]);
                    }
                    if (b != 0)
                    {
                        dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b - 1][c][d] + scores[target]);
                    }
                    if (c != 0)
                    {
                        dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c - 1][d] + scores[target]);
                    }
                    if (d != 0)
                    {
                        dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c][d - 1] + scores[target]);
                    }
                }
            }
        }
    }

    printf("%d\n", dp[cards[1]][cards[2]][cards[3]][cards[4]]);
    return 0;
}