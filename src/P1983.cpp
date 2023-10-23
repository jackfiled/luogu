#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int p, depth;

    Node(int p, int depth) : p(p), depth(depth) {}
};

struct Graph
{
    vector<vector<int>> points;
    int size;

    Graph(int number)
    {
        size = number;
        points = vector<vector<int>>(number + 1, vector<int>(number + 1, 0));
    }

    int topo()
    {
        vector<int> in = vector<int>(size + 1, 0);
        // 建立入度表
        for (int i = 1; i <= size; i++)
        {
            for (int j = 1; j <= size; j++)
            {
                if (points[i][j] == 1)
                {
                    in[j]++;
                }
            }
        }

        queue<Node> q;

        for (int i = 1; i <= size; i++)
        {
            if (in[i] == 0)
            {
                q.push(Node(i, 1));
            }
        }

        int result = 1;

        while (!q.empty())
        {
            auto &head = q.front();
            result = max(result, head.depth);

            for (int i = 1; i <= size; i++)
            {
                if (points[head.p][i] == 1)
                {
                    in[i]--;

                    if (in[i] == 0)
                    {
                        q.push(Node(i, head.depth + 1));
                    }
                }
            }

            q.pop();
        }

        return result;
    }
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    Graph graph(n);

    bool visit[n + 1];
    for (int i = 0; i < m; i++)
    {
        int c;
        scanf("%d", &c);

        memset(visit, false, sizeof(visit));
        int stations[c];

        for (int j = 0; j < c; j++)
        {
            scanf("%d", &stations[j]);
            visit[stations[j]] = true;
        }

        for (int j = 0; j < c; j++)
        {
            if (!visit[stations[j]])
            {
                continue;
            }

            for (int s = stations[0]; s <= stations[c - 1]; s++)
            {
                if (!visit[s])
                {
                    graph.points[stations[j]][s] = 1;
                }
            }
        }
    }

    printf("%d\n", graph.topo());
    return 0;
}