#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

// 计算一科需要花费的时间
int calc(int time[], int length)
{
    // 0-1背包问题
    // 但是费用和价值相同
    int dp[21][1201];
    memset(dp, 0, sizeof(dp));

    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += time[i];
    }

    int t = 0;
    for (int i = 1; i <= length; i++)
    {
        // 背包的大小最大为总时长的一半
        for (int j = 1; j <= sum / 2; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if (j >= time[i - 1])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - time[i - 1]] + time[i - 1]);
            }
            t = max(t, dp[i][j]);
        }
    }

    return max(t, sum  - t);
}

int main()
{
    int s1, s2, s3, s4;
    scanf("%d %d %d %d", &s1, &s2, &s3, &s4);

    int A[s1], B[s2], C[s3], D[s4];
    for (int i = 0; i < s1; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < s2; i++)
    {
        scanf("%d", &B[i]);
    }
    for (int i = 0; i < s3; i++)
    {
        scanf("%d", &C[i]);
    }
    for (int i = 0; i < s4; i++)
    {
        scanf("%d", &D[i]);
    }

    int result = calc(A, s1) + calc(B, s2) + calc(C, s3) + calc(D, s4);

    printf("%d\n", result);
    return 0;
}