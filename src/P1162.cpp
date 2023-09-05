#include <cstdio>
#include <queue>

using namespace std;

class BFS
{
public:
    int field[40][40];
    bool flag[40][40];
    int number;

    void init()
    {
        for (int i = 0; i < number; i++)
        {
            for (int j = 0; j < number; j++)
            {
                scanf("%d", &field[i][j]);
                visit[i][j] = false;
                flag[i][j] = false;
            }
        }

        for (int i = 0; i < number; i++)
        {
            // 边界上的0必然是非闭合的
            if (field[i][0] == 0)
            {
                flag[i][0] = true;
            }

            if (field[i][number - 1] == 0)
            {
                flag[i][number - 1] = true;
            }

            if (field[0][i] == 0)
            {
                flag[0][i] = true;
            }

            if (field[number - 1][i] == 0)
            {
                flag[number - 1][i] = true;
            }
        }
    }

    void bfs(int x, int y)
    {
        q.push(make_pair(x, y));
        visit[x][y] = true;

        while(!q.empty())
        {
            auto head = q.front();
            q.pop();
        
            flag[head.first][head.second] = true;

            for (int i = 0; i < 4; i++)
            {
                int nextX = head.first + delta[i][0], nextY = head.second + delta[i][1];

                if (inField(nextX, nextY) and field[nextX][nextY] == 0 and !visit[nextX][nextY])
                {
                    q.push(make_pair(nextX, nextY));
                    visit[nextX][nextY] = true;
                }
            }
        }
    }

    void print()
    {
        for (int i = 0; i < number; i++)
        {
            for (int j = 0; j < number; j++)
            {
                if (field[i][j] == 0 and !flag[i][j])
                {
                    printf("2 ");
                }
                else
                {
                    printf("%d ", field[i][j]);
                }
            }

            printf("\n");
        }
    }

private:
    bool visit[40][40];
    queue<pair<int, int>> q;
    int delta[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool inField(int x, int y)
    {
        return x >= 0 and x < number and y >= 0 and y < number;
    }
};

int main()
{
    BFS bfs;
    scanf("%d", &bfs.number);

    bfs.init();

    for (int i = 0; i < bfs.number; i++)
    {
        for (int j = 0; j < bfs.number; j++)
        {
            if (bfs.field[i][j] == 0 and bfs.flag[i][j])
            {
                bfs.bfs(i, j);
            }
        }
    }

    bfs.print();
    return 0;
}