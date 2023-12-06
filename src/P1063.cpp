#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int number;
    scanf("%d", &number);

    vector<int> array(2 * number + 1);
    for (int i = 1; i <= number; ++i)
    {
        scanf("%d", &array[i]);
        array[number + i] = array[i];
    }

    vector<vector<int>> dp(2 * number + 1, vector<int>(2 * number + 1, 0));

    for (int len = 1; len <= number; ++len)
    {
        for (int left = 1, right = left + len; right <= 2 * number; ++left, ++right)
        {
            for (int mid = left + 1; mid < right; ++mid)
            {
                dp[left][right] = max(dp[left][right], 
                    dp[left][mid] + dp[mid][right] + array[left] * array[mid] * array[right]);
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= number; ++i)
    {
        result = max(result, dp[i][number + i]);
    }

    printf("%d\n", result);

    return 0;
}