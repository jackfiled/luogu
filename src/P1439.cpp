#include <cstdio>

int main()
{
    int number;
    scanf("%d", &number);

    int a_pos[number + 1];

    for (int i = 1; i <= number; i++)
    {
        int t;
        scanf("%d", &t);
        a_pos[t] = i;
    }

    int b[number + 1];
    int dp[number + 1];

    for (int i = 1; i <= number; i++)
    {
        int t;
        scanf("%d", &t);

        b[a_pos[t]] = i;
        // 顺便初始化一下dp
        dp[i] = 0x7fffffff;
    }

    int len = 1;
    dp[0] = 0;

    for (int i = 1; i <= number; i++)
    {
        int l = 0, r = len;
        if (b[i] > dp[len])
        {
            len++;
            dp[len] = b[i];
        }
        else
        {
            while(l < r)
            {
                int mid = (l + r) / 2;
                if (dp[mid] > b[i])
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            dp[l] = b[i] < dp[l] ? b[i] : dp[l];
        }
    }
    
    printf("%d\n", len);
    return 0;
}