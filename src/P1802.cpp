#include <cstdio>
#include <cstring>
#define MAX(a, b) (a) > (b) ? (a) : (b)

struct Node
{
    int win;
    int lose;
    int use;
};

int main()
{
    int number, x;
    scanf("%d %d", &number, &x);

    Node nodes[number + 1];
    for (int i = 1; i <= number; i++)
    {
        scanf("%d %d %d", &nodes[i].lose, &nodes[i].win, &nodes[i].use);
    }

    int dp[number + 1][x + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= number; i++)
    {
        for (int j = x; j >= 0; j--)
        {
            if (j >= nodes[i].use)
            {
                dp[i][j] = MAX(dp[i - 1][j] + nodes[i].lose, dp[i -1][j - nodes[i].use] + nodes[i].win);
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + nodes[i].lose;
            }
        }
    }

    printf("%lld\n", dp[number][x] * 5ll);
    return 0;
}