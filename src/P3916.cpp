#include <cstdio>
#include <vector>
#include <memory>

using namespace std;

struct Graph
{
    unique_ptr<vector<int>[]> points;
    unique_ptr<int[]> distance;
    int size;

    Graph(int number)
    {
        size = number;

        points = unique_ptr<vector<int>[]>(new vector<int>[number + 1]);
        distance = unique_ptr<int[]>(new int[number + 1]);

        for (int i = 1; i <= number; i++)
        {
            distance[i] = 0;
        }
    }

    void dfs(int x, int d)
    {
        if (distance[x] != 0)
        {
            return;
        }

        distance[x] = d;
        
        for (auto i : points[x])
        {
            dfs(i, d);
        }
    }
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    Graph graph(n);

    for (int i = 0; i < m; i++)
    {
        int begin, end;
        scanf("%d %d", &begin, &end);

        graph.points[end].push_back(begin);
    }

    for (int i = n; i >= 1; i--)
    {
        graph.dfs(i, i);
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", graph.distance[i]);
    }
    printf("\n");

    return 0;
}