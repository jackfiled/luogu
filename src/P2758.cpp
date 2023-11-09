#include <cstdio>
#include <cstring>
#include <vector>
#define MIN(a, b) (a) < (b) ? (a) : (b)

using namespace std;

struct DP
{
    char A[2010];
    char B[2010];
    int aLength, bLength;

    vector<vector<int>> dp;

    DP()
    {
        char a[2010];
        char b[2010];
        scanf("%s", a);
        scanf("%s", b);

        // 字符串从1开始好一点
        aLength = strlen(a);
        for (int i = 0; i < aLength; i++)
        {
            A[i + 1] = a[i];
        }
        bLength = strlen(b);
        for (int i = 0; i < bLength; i++)
        {
            B[i + 1] = b[i];
        }

        // dp[i][j] 从A[i]变成B[j]需要的步数
        dp = vector<vector<int>>(aLength + 1, vector<int>(bLength + 1, -1));
    }

    int edit(int i, int j)
    {
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (i == 0)
        {
            dp[i][j] = j;
            return j;
        }

        if (j == 0)
        {
            dp[i][j] = i;
            return i;
        }

        // 首先考虑删除或者添加
        int delta = MIN(edit(i - 1, j) + 1, edit(i, j - 1) + 1);

        // 考虑修改
        if (A[i] == B[j])
        {
            delta = MIN(delta, edit(i - 1, j - 1));
        }
        else
        {
            delta = MIN(delta, edit(i - 1, j - 1) + 1);
        }

        dp[i][j] = delta;
        return delta;
    }
};

int main()
{
    DP dp;

    printf("%d\n", dp.edit(dp.aLength, dp.bLength));
    return 0;
}