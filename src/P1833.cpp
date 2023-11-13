#include <cstdio>
#include <cstring>
#include <vector>

#define MAX(a, b) (a) > (b) ? (a) : (b)

using namespace std;

struct Sakura
{
    int time, value, p;
};

struct Item
{
    int time, value;
};

int main()
{
    int startHour, startMinute, endHour, endMinute;
    scanf("%d:%d %d:%d", &startHour, &startMinute, &endHour, &endMinute);

    int time = endMinute - startMinute + (endHour - startHour) * 60;

    int n;
    scanf("%d", &n);

    Sakura sakuras[n + 1];

    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d %d", &sakuras[i].time, &sakuras[i].value, &sakuras[i].p);

        if (sakuras[i].p == 0)
        {
            sakuras[i].p = 9999999;
        }
    }

    vector<Item> items;
    for (int i = 1; i <= n; i++)
    {
        int index = 1;

        while (sakuras[i].p != 0)
        {
            Item item = {
                .time = sakuras[i].time * index,
                .value = sakuras[i].value * index
            };
            items.emplace_back(item);

            sakuras[i].p -= index;
            index = index * 2;

            if (sakuras[i].p < index)
            {
                Item item = {
                    .time = sakuras[i].time * sakuras[i].p,
                    .value = sakuras[i].value * sakuras[i].p
                };

                items.emplace_back(item);
                break;
            }
        }
    }

    int dp[time + 1];
    memset(dp, 0, sizeof(dp));

    for (const auto& item : items)
    {
        for (int i = time; i >= item.time; i--)
        {
            dp[i] = MAX(dp[i], dp[i - item.time] + item.value);
        }
    }

    printf("%d\n", dp[time]);
    return 0;
}