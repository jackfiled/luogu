#include <cstdio>
#include <cstring>

int main()
{
    int f, v;
    scanf("%d %d", &f, &v);

    int matrix[f + 1][v + 1];

    for (int i = 1; i <= f; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 花瓶放在当前位置的最大美学值
    int dp[f + 1][v + 1];
    memset(dp, 0x80000000, sizeof(dp));
    // 前一个花瓶放置的位置
    int pre[f + 1][v + 1];
    memset(pre, 0, sizeof(pre));

    for (int i = 1; i <= f; i++)
    {
        // 给前面的花瓶留下空间
        for (int j = i; j <= v; j++)
        {
            // 选择前面花瓶能取的最大值
            int max = 0x80000000;
            int pos;
            for (int k = i - 1; k <= j - 1; k++)
            {
                if (dp[i - 1][k] > max)
                {
                    pos = k;
                    max = dp[i - 1][k];
                }
            }

            // 特殊判断第一行
            if (i == 1)
            {
                max = 0;
            }

            dp[i][j] = max + matrix[i][j];
            // 记录前面花瓶取的位置
            pre[i][j] = pos;
        }
    }

    int result = 0x80000000;
    int pos = 0;
    for (int i = f; i <= v; i++)
    {
        if (dp[f][i] > result)
        {
            pos = i;
            result = dp[f][i];
        }
    }

    printf("%d\n", result);

    // 反向遍历获取放花瓶的位置
    int array[f + 1];
    array[f] = pos;

    for (int i = f - 1; i >= 1; i--)
    {
        array[i] = pre[i + 1][pos];
        pos = array[i];
    }

    for (int i = 1; i <= f; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}