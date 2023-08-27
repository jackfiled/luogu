#include <cstdio>
#include <queue>

using namespace std;

class BFS
{
public:
    BFS(int n, int m)
    {
        this->n = n;
        this->m = m;
        matrix = new int*[n + 1];

        for (int i = 1; i <= n; i++)
        {
            matrix[i] = new int[m + 1];

            for (int j = 1; j <= m; j++)
            {
                matrix[i][j] = -1;
            }
        }
    }

    ~BFS()
    {
        for (int i = 1; i <= n; i++)
        {
            delete matrix[i];
        }

        delete matrix;
    }

    void print()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                printf("%-5d", matrix[i][j]);
            }
            printf("\n");
        }
    }

    void bfs(int x, int y)
    {
        matrix[x][y] = 0;
        q.push(make_pair(x, y));

        while (!q.empty())
        {
            int headX = q.front().first, headY = q.front().second;
            q.pop();

            for (int i = 0; i < 8; i++)
            {
                int nextX = headX + dx[i], nextY = headY + dy[i];

                if (nextX >= 1 and nextX <= n and nextY >= 1 and nextY <= m)
                {
                    if (matrix[nextX][nextY] == -1)
                    {
                        matrix[nextX][nextY] = matrix[headX][headY] + 1;
                        q.push(make_pair(nextX, nextY));
                    }
                }
            }
        }
    }

private:
    int **matrix;
    int n, m;
    queue<pair<int, int>> q;

    const int dx[8] = {-2, -1, -1, -2, 1, 2, 2, 1};
    const int dy[8] = {-1, -2, 2, 1, -2, -1, 1, 2};
};

int main()
{
    int n, m, x, y;
    scanf("%d %d %d %d", &n, &m, &x, &y);

    BFS bfs(n, m);

    bfs.bfs(x, y);

    bfs.print();

    return 0;
}