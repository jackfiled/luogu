#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MIN(a, b) (a) < (b) ? (a) : (b)

int main()
{
    char input[60];
    scanf("%s", input);
    int target;
    scanf("%d", &target);

    int length = strlen(input);

    long long nums[length + 1][length + 1];

    for (int i = 1; i <= length; i++)
    {
        nums[i][i] = input[i - 1] - '0';

        for (int j = i + 1; j <= length and j - i <= 11; j++)
        {
            nums[i][j] = nums[i][j - 1] * 10 + input[j - 1] - '0';
        }
    }

    vector<vector<int>> dp(length + 1, vector<int>(100007, 0x3f));
    dp[0][0] = 0;

    for (int i = 1; i <= length; i++)
    {
        for (int k = 1; k <= 11; k++)
        {
            if (k <= i)
            {
                for (long long j = nums[i - k + 1][i]; j <= target; j++)
                {
                    dp[i][j] = MIN(dp[i][j], dp[i - k][j - nums[i - k + 1][i]] + 1);
                }
            }
        }
    }

    if (dp[length][target] > length)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", dp[length][target] - 1);
    }

    return 0;
}
