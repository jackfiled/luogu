#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct Item 
{
    int pos, value;

    Item(int pos, int value) : pos(pos), value(value)
    {

    }
};

int main()
{
    int n, l, r;
    scanf("%d %d %d", &n, &l, &r);

    int values[n + 1];

    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &values[i]);
    }

    deque<Item> items;
    vector<int> dp(n + 1, 0x80000000);
    dp[0] = 0;

    int result = 0x80000000;
    for (int i = l; i <= n; i++)
    {
        // 弹出过期的元素
        while (!items.empty() and items.front().pos < i - r)
        {
            items.pop_front();
        }

        // 弹出比当前欲插入的元素dp[i - l]小的元素
        while (!items.empty() and items.back().value < dp[i - l])
        {
            items.pop_back();
        }
        items.push_back(Item(i - l, dp[i - l]));

        dp[i] = items.front().value + values[i];

        if (i + r > n)
        {
            result = max(result, dp[i]);
        }
    }

    printf("%d\n", result);
    return 0;
}