#include <cstdio>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

struct Graph
{
    int size;
    vector<unordered_set<int>> points;

    Graph(int number)
    {
        size = number;
        points = vector<unordered_set<int>>(number + 1);
    }

    unordered_set<int> bfs(int x)
    {
        unordered_set<int> s;
        queue<int> q;

        q.push(x);

        while (!q.empty())
        {
            int head = q.front();
            q.pop();

            if (s.count(head) == 0)
            {
                s.emplace(head);

                for (auto& i : points[head])
                {
                    if (s.count(i) == 0)
                    {
                        q.push(i);
                    }
                }
            }
        }


        return s;
    }
};

int main()
{
    int k, n, m;
    scanf("%d %d %d", &k, &n, &m);
    int begins[k];

    for (int i = 0; i < k; i++)
    {
        scanf("%d", &begins[i]);
    }

    Graph graph(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        graph.points[a].emplace(b);
    }

    unordered_set<int> sets[k];
    for (int i = 0; i < k; i++)
    {
        sets[i] = graph.bfs(begins[i]);
    }

    unordered_set<int>& result = sets[0];

    for (int i = 1; i < k; i++)
    {
        for (auto itor = result.begin(); itor != result.end();)
        {
            if (sets[i].count(*itor) == 0)
            {
                itor = result.erase(itor);
            }
            else
            {
                itor++;
            }
        }
    }

    printf("%ld\n", result.size());

    return 0;
}