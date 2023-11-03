#include <cstdio>
#include <cmath>
#define MIN(a ,b) (a) < (b) ? (a) : (b)

int main()
{
    int number;
    scanf("%d", &number);

    int left[number + 1], right[number + 1];

    for (int i = 1; i <= number; i++)
    {
        scanf("%d %d", &left[i], &right[i]);
    }

    int dp[number + 1][2];
    dp[1][0] = right[1] + right[1] - left[1] - 1;
    dp[1][1] = right[1] - 1;

    for (int i = 2; i <= number; i++)
    {
        dp[i][0] = MIN(dp[i - 1][0] + abs(left[i - 1] - right[i]) + right[i] - left[i] + 1,
            dp[i - 1][1] + abs(right[i - 1] - right[i]) + right[i] - left[i] + 1);

        dp[i][1] = MIN(dp[i - 1][0] + abs(left[i - 1] - left[i]) + right[i] - left[i] + 1,
            dp[i - 1][1] + abs(right[i - 1] - left[i]) + right[i] - left[i] + 1);        
    }

    printf("%d\n", MIN(dp[number][0] + number - left[number], dp[number][1] + number - right[number]));
    return 0;
}