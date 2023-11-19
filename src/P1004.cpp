#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

struct DFS
{
    int size;
    vector<vector<int>> matrix;
    // 记录状态是否访问过
    unordered_map<int, int> record;

    DFS()
    {
        scanf("%d", &size);

        matrix.resize(size + 1);

        for (auto& l : matrix)
        {
            l.resize(size + 1, 0);
        }

        int x, y, z;
        while (true)
        {
            scanf("%d %d %d", &x, &y, &z);
            if (x == 0 and y == 0 and z == 0)
            {
                break;
            }

            matrix[x][y] = z;
        }
    }

    int dfs(int x1, int y1, int x2, int y2)
    {
        if (record.count(hash(x1, y1, x2, y2)) != 0)
        {
            return record.at(hash(x1, y1, x2, y2));
        }

        if (x1 == size and y1 == size and x2 == size and y2 == size)
        {
            return 0;
        }

        int result = 0;
        if (x1 < size and x2 < size)
        {
            // 尝试往下走
            if (x1 + 1 == x2 + 1 and y1 == y2)
            {
                result = max(result, dfs(x1 + 1, y1, x2 + 1, y2) + matrix[x1 + 1][y1]);
            }
            else
            {
                result = max(result, dfs(x1 + 1, y1, x2 + 1, y2) + matrix[x1 + 1][y1] + matrix[x2 + 1][y2]);
            }
        }

        if (x1 < size and y2 < size)
        {
            // 1下 2右
            if (x1 + 1 == x2 and y1 == y2 + 1)
            {
                result = max(result, dfs(x1 + 1, y1, x2, y2 + 1) + matrix[x1 + 1][y1]);
            }
            else
            {
                result = max(result, dfs(x1 + 1, y1, x2, y2 + 1) + matrix[x1 + 1][y1] + matrix[x2][y2 + 1]);
            }
        }

        if (y1 < size and x2 < size)
        {
            // 1右 2下
            if (x1 == x2 + 1 and y1 + 1 == y2)
            {
                result = max(result, dfs(x1, y1 + 1, x2 + 1, y2) + matrix[x1][y1 + 1]);
            }
            else
            {
                result = max(result, dfs(x1, y1 + 1, x2 + 1, y2) + matrix[x1][y1 + 1] + matrix[x2 + 1][y2]);
            }
        }

        if (y1 < size and y2 < size)
        {
            // 尝试往下走
            if (x1 == x2 and y1 + 1 == y2 + 1)
            {
                result = max(result, dfs(x1, y1 + 1, x2, y2 + 1) + matrix[x1][y1 + 1]);
            }
            else
            {
                result = max(result, dfs(x1, y1 + 1, x2, y2 + 1) + matrix[x1][y1 + 1] + matrix[x2][y2 + 1]);
            }
        }

        record.emplace(make_pair(hash(x1, y1, x2, y2), result));
        return result;
    }

    int hash(int x1, int y1, int x2, int y2)
    {
        // AS x, y <= 9
        return x1 * 1000 + y1 * 100 + x2 * 10 + y2;
    }
};

int main()
{
    DFS dfs;

    printf("%d\n", dfs.dfs(1, 1, 1, 1) + dfs.matrix[1][1]);
    return 0;
}