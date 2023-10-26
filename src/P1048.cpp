#include <cstdio>
#include <cstring>
#define MAX(a, b) (a) > (b) ? (a) : (b)

int main()
{
    int time, number;
    scanf("%d %d", &time, &number);

    int times[number + 1];
    int values[number];

    for (int i = 1; i <= number; i++)
    {
        scanf("%d %d", &times[i], &values[i]);
    }

    int dp[number + 1][time + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= number; i++)
    {
        for (int j = time; j >= 0; j--)
        {
            if (j >= times[i])
            {
                dp[i][j] = MAX(dp[i - 1][j], dp[i - 1][j - times[i]] + values[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printf("%d\n", dp[number][time]);
    return 0;
}