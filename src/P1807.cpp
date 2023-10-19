#include <cstdio>
#include <vector>
#include <memory>
#include <queue>
#include <unordered_set>

using namespace std;

struct Graph
{
    int size;
    vector<unordered_set<int>> points;
    vector<vector<int>> matrix;

    Graph(int number)
    {
        size = number;
        points = vector<unordered_set<int>>(number + 1);
        matrix = vector<vector<int>>(number, vector<int>(number + 1));
    }

    vector<int> bfs(int x)
    {
        queue<int> q;
        q.push(x);

        vector<int> result(size + 1);
        for (int& i : result)
        {
            i = -1;
        }
        result[1] = 0;

        while (!q.empty())
        {
            int head = q.front();
            q.pop();

            for (int i : points[head])
            {
                if (result[head] + matrix[head][i] > result[i])
                {
                    result[i] = result[head] + matrix[head][i];
                    q.push(i);
                }
            }
        }

        return result;
    }
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    Graph graph(n);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        // 只保存两点之间最长的边
        graph.points[a].emplace(b);
        graph.matrix[a][b] = max(graph.matrix[a][b], c);
    }

    vector<int> result = graph.bfs(1);
    printf("%d\n", result[n]);

    return 0;
}