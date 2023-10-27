#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct DFS
{
    vector<int> pre;

    DFS(int number)
    {
        pre = vector<int>(number + 1, 0);
    }

    void search(int x)
    {
        if (pre[x] != 0)
        {
            search(pre[x]);
        }
        printf("%d ", x);
    }
};

int main()
{
    int number;
    scanf("%d", &number);

    int values[number + 1];
    int connections[number + 1][number + 1];
    memset(connections, 0, sizeof(connections));

    for (int i = 1 ; i <= number; i++)
    {
        scanf("%d", &values[i]);
    }

    for (int i = 1; i < number; i++)
    {
        for (int j = i + 1; j <= number; j++)
        {
            scanf("%d", &connections[i][j]);
        }
    }

    int dp[number + 1];
    dp[1] = values[1];

    int answer = dp[1], pos = 1;
    DFS dfs(number);
    for (int i = 2; i <= number; i++)
    {
        dp[i] = values[i];

        for (int j = i - 1; j > 0; j--)
        {
            if (connections[j][i] != 0 and dp[i] < dp[j] + values[i])
            {
                dp[i] = dp[j] + values[i];
                dfs.pre[i] = j;
            }
        }

        if (answer < dp[i])
        {
            answer = dp[i];
            pos = i;
        }
    }

    dfs.search(pos);
    printf("\n");
    printf("%d\n", answer);

    return 0;
}