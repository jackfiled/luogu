#include <cstdio>
#include <cmath>
#include <cstring>
#define min(a, b) (((a) < (b)) ? (a) : (b))

struct Pos
{
    double x, y;
};

double d(Pos &a, Pos &b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// dp 数组
// 在第i个点上走过状态为j时的最短距离
double dp[18][100000];

int main()
{
    memset(dp, 127, sizeof(dp));
    // 两块奶酪之间的距离
    double distance[20][20];

    int number;
    scanf("%d", &number);
    Pos array[number + 1];
    array[0] = {
        .x = 0,
        .y = 0};
    for (int i = 1; i <= number; i++)
    {
        scanf("%lf %lf", &array[i].x, &array[i].y);
    }

    for (int i = 0; i <= number; i++)
    {
        for (int j = i + 1; j <= number; j++)
        {
            distance[i][j] = d(array[i], array[j]);
            distance[j][i] = distance[i][j];
        }
    }

    // 初始化dp数组
    for (int i = 1; i <= number; i++)
    {
        dp[i][(1 << (i - 1))] = distance[0][i];
    }

    for (int state = 1; state < (1 << number); state++)
    {
        // 遍历所有的状态

        // 当前所在点的位置
        for (int i = 1; i <= number; i++)
        {
            if ((state & (1 << (i - 1))) == 0)
            {
                continue;
            }

            // 当前能到达的点
            for (int j = 1; j <= number; j++)
            {
                if (i == j)
                {
                    continue;
                }

                if ((state & (1 << (j - 1))) == 0)
                {
                    continue;
                }

                dp[i][state] = min(dp[i][state], dp[j][state - (1 << (i - 1))] + distance[i][j]);
            }
        }
    }

    double result;
    memset(&result, 127, sizeof(result));
    for (int i = 1; i <= number; i++)
    {
        result = min(result, dp[i][(1 << number) - 1]);
    }

    printf("%.2lf\n", result);
    return 0;
}