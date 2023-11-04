#include <cstdio>
#include <cstring>
#define MAX(a, b) (a) > (b) ? (a) : (b)

struct Item
{
    int cost = 0;
    int value = 0;
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    Item items[m + 1];
    int annexCount[m + 1];
    Item annexItems[m + 1][2];

    memset(annexCount, 0, sizeof(annexCount));

    for (int i = 1; i <= m; i++)
    {
        int cost, value, p;
        scanf("%d %d %d", &cost, &value, &p);

        if (p == 0)
        {
            items[i].cost = cost;
            items[i].value = value * cost;
        }
        else
        {
            annexItems[p][annexCount[p]].cost = cost;
            annexItems[p][annexCount[p]].value = value * cost;
            annexCount[p]++;
        }
    }

    int dp[n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= m; i++)
    {
        if (items[i].cost == 0 and items[i].value == 0)
        {
            // 附属物品 
            continue;
        }

        for (int j = n; j >= items[i].cost; j--)
        {
            dp[j] = MAX(dp[j], dp[j - items[i].cost] + items[i].value);

            if (j >= items[i].cost + annexItems[i][0].cost)
            {
                dp[j] = MAX(dp[j], dp[j - items[i].cost - annexItems[i][0].cost]
                    + items[i].value + annexItems[i][0].value);
            }

            if (j >= items[i].cost + annexItems[i][1].cost)
            {
                dp[j] = MAX(dp[j], dp[j - items[i].cost - annexItems[i][1].cost]
                    + items[i].value + annexItems[i][1].value);
            }

            if (j >= items[i].cost + annexItems[i][0].cost + annexItems[i][1].cost)
            {
                dp[j] = MAX(dp[j], dp[j - items[i].cost - annexItems[i][0].cost - annexItems[i][1].cost]
                    + items[i].value + annexItems[i][0].value + annexItems[i][1].value);
            }
        }
    }

    printf("%d\n", dp[n]);
    return 0;
}