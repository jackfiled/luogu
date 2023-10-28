#include <cstdio>
#define MAX(a, b) (a) > (b) ? (a) : (b)

using namespace std;

int main()
{
    int number;
    scanf("%d", &number);

    int values[number];

    for (int i = 0; i < number; i++)
    {
        scanf("%d", &values[i]);
    }

    int dp[number];
    dp[0] = values[0];
    int answer = values[0];

    for (int i = 1; i < number; i++)
    {
        dp[i] = values[i];

        if (dp[i] < dp[i - 1] + values[i])
        {
            dp[i] = dp[i - 1] + values[i];
        }
        answer = MAX(dp[i], answer);
    }

    printf("%d\n", answer);
    return 0;
}