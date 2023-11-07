#include <iostream>
#include <cmath>
#define MAX(a, b) (a) > (b) ? (a) : (b)

struct Mouse
{
    int x, y;
    int time;

    int distance(const Mouse& m)
    {
        return abs(x - m.x) + abs(y - m.y);
    }
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    Mouse mice[m];

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &mice[i].time, &mice[i].x, &mice[i].y);
    }

    int dp[m];
    for (int i = 0; i < m; i++)
    {
        dp[i] = 1;
    }

    int result = dp[0];
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (mice[i].distance(mice[j]) <= abs(mice[i].time - mice[j].time))
            {
                dp[i] = MAX(dp[i], dp[j] + 1);
            }
        }

        result = MAX(result, dp[i]);
    }

    printf("%d\n", result);
    return 0;
}