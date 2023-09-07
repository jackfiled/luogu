#include <cstdio>
#include <map>
#include <queue>

using namespace std;

struct Pos
{
    int x, y;
    int step;
};

struct Teleport
{
    Pos one;
    Pos two;
};

class BFS
{
public:
    char field[400][400];
    int height, width;
    int step = -1;

    void generateTeleports()
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (field[i][j] >= 'A' and field[i][j] <= 'Z')
                {
                    auto iter = teleports.find(field[i][j]);

                    if (iter == teleports.end())
                    {
                        Teleport teleport = {
                            .one = {
                                .x = i,
                                .y = j}};

                        teleports[field[i][j]] = teleport;
                    }
                    else
                    {
                        iter->second.two = {
                            .x = i,
                            .y = j};
                    }
                }

                visit[i][j] = false;
            }
        }
    }

    void bfs(const Pos &start)
    {
        int delta[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

        q.push(start);

        while (!q.empty())
        {
            auto head = q.front();
            q.pop();

            if (field[head.x][head.y] == '=')
            {
                step = head.step;
                break;
            }

            if (field[head.x][head.y] >= 'A' and field[head.x][head.y] <= 'Z')
            {
                auto iter = teleports.find(field[head.x][head.y]);

                if (iter != teleports.end())
                {
                    if (head.x == iter->second.one.x and head.y == iter->second.one.y)
                    {
                        head.x = iter->second.two.x;
                        head.y = iter->second.two.y;
                    }
                    else
                    {
                        head.x = iter->second.one.x;
                        head.y = iter->second.one.y;
                    }
                }
            }

            for (int pos = 0; pos < 4; pos++)
            {
                int nextX = head.x + delta[pos][0], nextY = head.y + delta[pos][1];

                if (nextX >= 0 and nextX < height and nextY >= 0 and nextY < width)
                {
                    if (field[nextX][nextY] != '#')
                    {
                        if (!visit[nextX][nextY])
                        {
                            Pos next = {
                                .x = nextX,
                                .y = nextY,
                                .step = head.step + 1};

                            q.push(next);
                            visit[nextX][nextY] = true;
                        }
                    }
                }
            }

            //print();
        }
    }

private:
    queue<Pos> q;
    bool visit[400][400];
    map<char, Teleport> teleports;

    void print()
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (visit[i][j] and !(field[i][j] >= 'A' and field[i][j] <= 'Z'))
                {
                    printf("!");
                }
                else
                {
                    printf("%c", field[i][j]);
                }
            }

            printf("\n");
        }
    }
};

int main()
{
    BFS bfs;

    scanf("%d %d\n", &bfs.height, &bfs.width);

    Pos start;
    for (int i = 0; i < bfs.height; i++)
    {
        char input[400];
        fgets(input, 400, stdin);

        for (int j = 0; j < bfs.width; j++)
        {
            bfs.field[i][j] = input[j];

            if (input[j] == '@')
            {
                start.x = i;
                start.y = j;
                start.step = 0;
            }
        }
    }

    bfs.generateTeleports();
    bfs.bfs(start);

    printf("%d\n", bfs.step);
    return 0;
}