#include <cstdio>
#include <vector>
#include <queue>
#include <memory>
#include <algorithm>

using namespace std;

struct Edge
{
    int begin, end;

    Edge(int b, int e)
    {
        begin = b;
        end = e;
    }
};

bool compare(const Edge& a, const Edge& b)
{
    if (a.end == b.end)
    {
        return a.begin < b.begin;
    }

    return a.end < b.end;
}

struct Search
{
    vector<Edge> edges;
    unique_ptr<vector<int>[]> points;
    unique_ptr<bool[]> visit;

    int size;

    Search(int number)
    {
        points = unique_ptr<vector<int>[]>(new vector<int>[number + 1]);
        visit = unique_ptr<bool[]>(new bool[number + 1]);

        size = number;
    }

    void clearVisit()
    {
        for (int i = 1; i <= size; i++)
        {
            visit[i] = false;
        }
    }

    void dfs(int x)
    {
        visit[x] = true;
        printf("%d ", x);

        for(auto& i : points[x])
        {
            int end = edges[i].end;
            if (!visit[end])
            {
                dfs(end);
            }
        }
    }

    void bfs(int x)
    {
        queue<int> q;

        q.push(x);
        visit[x] = true;
        printf("%d ", x);

        while(!q.empty())
        {
            int head = q.front();

            for (auto& i : points[head])
            {
                int end = edges[i].end;

                if (!visit[end])
                {
                    q.push(end);
                    visit[end] = true;
                    printf("%d ", end);
                }
            }

            q.pop();
        }
    }
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    Search search(n);

    for (int i = 0; i < m; i++)
    {
        int begin, end;
        scanf("%d %d", &begin, &end);

        search.edges.push_back(Edge(begin, end));
    }

    sort(search.edges.begin(), search.edges.end(), compare);

    for (int i = 0; i < m; i++)
    {
        search.points[search.edges[i].begin].push_back(i);
    }

    search.clearVisit();
    search.dfs(1);
    printf("\n");

    search.clearVisit();
    search.bfs(1);
    printf("\n");

    return 0;
}