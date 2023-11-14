#include <cstdio>
#include <cstring>
#include <vector>
#define LENGTH 800000

using namespace std;

struct Cow
{
    int i, e;
};

int main()
{
    int n;
    scanf("%d", &n);

    vector<Cow> cows(n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &cows[i].i, &cows[i].e);
    }

    // dp[i] 表示智商为i时，最大的情商值
    vector<int> dp(LENGTH + 1, -800000000);
    dp[LENGTH / 2] = 0;

    for (const auto& cow : cows)
    {
        if (cow.i >= 0)
        {
            for (int i = LENGTH; i >= cow.i; i--)
            {
                dp[i] = max(dp[i], dp[i - cow.i] + cow.e);
            }
        }
        else
        {
            for (int i = 0; i <= LENGTH + cow.i; i++)
            {
                dp[i] = max(dp[i], dp[i - cow.i] + cow.e);
            }
        }
    }
    
    int result = 0;

    for (int i = LENGTH / 2; i <= LENGTH; i++)
    {
        if (dp[i] >= 0)
        {
            result = max(result, dp[i] + i - LENGTH / 2);
        }
    }
    printf("%d\n", result);
    return 0;
}