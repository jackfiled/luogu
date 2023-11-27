#include <cstdio>
#include <vector>

using namespace std;

struct DFS
{
    int length;
    // 实际上是前缀和
    // 同时用二倍链模拟
    vector<int> stones;
    vector<vector<int>> dpMin;
    vector<vector<int>> dpMax;
 
    const int inf = 0x7fffffff;

    DFS()
    {
        scanf("%d", &length);

        stones.resize(2 * length + 1, 0);

        for (int i = 1; i <= length; i++)
        {
            scanf("%d", &stones[i]);
            stones[i + length] = stones[i];
        }

        for (int i = 1; i <= 2 * length; i++)
        {
            stones[i] += stones[i - 1];
        }

        dpMin = vector<vector<int>>(2 * length + 1, vector<int>(2 * length + 1, 0));
        dpMax = vector<vector<int>>(2 * length + 1, vector<int>(2 * length + 1, 0));
    }

    int dfsMin(int l, int r)
    {
        if (dpMin[l][r] != 0)
        {
            return dpMin[l][r];
        }

        if (l == r)
        {
            dpMin[l][r] = 0;
            return 0;
        }

        int result = inf;
        for (int m = l; m < r; m++)
        {
            // 找合并[l, m], [m + 1, r]的最小代价
            result = min(result, dfsMin(l, m) + dfsMin(m + 1, r) + stones[r] - stones[l - 1]);
        }

        dpMin[l][r] = result;
        return result;
    }

    int dfsMax(int l, int r)
    {
        if (dpMax[l][r] != 0)
        {
            return dpMax[l][r];
        }

        if (l == r)
        {
            dpMax[l][r] = 0;
            return 0;
        }

        int result = 0;
        for (int m = l; m < r; m++)
        {
            result = max(result, dfsMax(l, m) + dfsMax(m + 1, r) + stones[r] - stones[l - 1]);
        }

        dpMax[l][r] = result;
        return result;
    }
};

int main()
{
    DFS dfs;

    dfs.dfsMin(1, dfs.length * 2);
    dfs.dfsMax(1, dfs.length * 2);

    int resultMin = dfs.inf, resultMax = 0; 
    for (int i = 1; i <= dfs.length; i++)
    {
        resultMin = min(resultMin, dfs.dpMin[i][i + dfs.length - 1]);
        resultMax = max(resultMax, dfs.dpMax[i][i + dfs.length - 1]);
    }

    printf("%d\n%d\n", resultMin, resultMax);
    return 0;
}