#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> array(n + 1);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &array[i]);
    }

    // 第i位为1的最大子序列长度
    vector<int> dp(31, 0);
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        int m = 1;
        for (int c = 0; c <= 30; c++)
        {
            if (((1 << c) & array[i]) != 0)
            {
                // 第i位不为1
                m = max(dp[c] + 1, m);
            }
        }

        for (int c = 0; c <= 30; c++)
        {
            if (((1 << c) & array[i]) != 0)
            {
                // 第i位不为1
                dp[c] = max(dp[c], m);
            }
        }

        result = max(result, m);
    }

    printf("%d\n", result);
    return 0;
}