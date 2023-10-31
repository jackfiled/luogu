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

    long long dp[time + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= number; i++)
    {
        for (int j = times[i]; j <= time; j++)
        {
            dp[j] = MAX(dp[j], dp[j - times[i]] + values[i]);
        }
    }

    printf("%lld\n", dp[time]);
    return 0;
}