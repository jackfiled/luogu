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

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0x7fffffff));

    for (int i = 1; i <= n; ++i)
    {
        dp[i][i] = 1;
    }
    
    for (int i = 1; i < n; ++i)
    {
        if (array[i] == array[i + 1])
        {
            dp[i][i + 1] = 1;
        }
        else
        {
            dp[i][i + 1] = 2;
        }
    }

    for (int len = 3; len <= n; ++len)
    {
        for (int l = 1; l + len - 1 <= n; ++l)
        {
            int r = l + len - 1;

            if (array[l] == array[r])
            {
                dp[l][r] = dp[l + 1][r - 1];
            }

            for (int mid = l; mid < r; ++mid)
            {
                dp[l][r] = min(dp[l][r], dp[l][mid] + dp[mid + 1][r]);
            }
        }
    }

    printf("%d\n", dp[1][n]);
    return 0;
}