#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

struct State
{
    int time, x, y;

    bool valid()
    {
        return x >= 0 and y >= 0;
    }
};

class BFS
{
public:
    int result = -1;

    BFS(State *meteor, int meteor_number)
    {
        for (int i = 0; i < 400; i++)
        {
            for (int j = 0; j < 400; j++)
            {
                field[i][j] = 10000;
                visit[i][j] = false;
            }
        }

        for (int i = 0; i < meteor_number; i++)
        {
            int x = meteor[i].x;
            int y = meteor[i].y;
            int time = meteor[i].time;

            field[x][y] = min(time, field[x][y]);
            field[x + 1][y] = min(time, field[x + 1][y]);
            field[x][y + 1] = min(time, field[x][y + 1]);

            if (x - 1 >= 0)
            {
                field[x - 1][y] = min(time, field[x - 1][y]);
            }
            if (y - 1 >= 0)
            {
                field[x][y - 1] = min(time, field[x][y - 1]);
            }
        }

        State init_state = {
            .time = 0,
            .x = 0,
            .y = 0};

        q.push(init_state);

        visit[0][0] = true;
    }

    void bfs()
    {
        while (!q.empty())
        {
            auto head = q.front();
            q.pop();

            if (check(head))
            {
                result = head.time;
                break;
            }

            State up_state = {
                .time = head.time + 1,
                .x = head.x,
                .y = head.y - 1,
            };
            if (check_along(up_state))
            {
                visit[up_state.x][up_state.y] = true;
                q.push(up_state);
            }

            State down_state = {
                .time = head.time + 1,
                .x = head.x,
                .y = head.y + 1,
            };
            if (check_along(down_state))
            {
                visit[down_state.x][down_state.y] = true;
                q.push(down_state);
            }

            State left_state = {
                .time = head.time + 1,
                .x = head.x - 1,
                .y = head.y,
            };
            if (check_along(left_state))
            {
                visit[left_state.x][left_state.y] = true;
                q.push(left_state);
            }

            State right_state = {
                .time = head.time + 1,
                .x = head.x + 1,
                .y = head.y,
            };
            if (check_along(right_state))
            {
                visit[right_state.x][right_state.y] = true;
                q.push(right_state);
            }
        }
    }

private:
    queue<State> q;

    int field[400][400];
    bool visit[400][400];

    bool check(State &now)
    {
        return field[now.x][now.y] == 10000;
    }

    bool check_along(State &now)
    {
        if (now.x < 0 or now.y < 0)
        {
            return false;
        }

        if (visit[now.x][now.y])
        {
            return false;
        }

        return now.time < field[now.x][now.y];
    }
};

int main()
{
    int number;
    scanf("%d", &number);
    State meteor[number];
    for (int i = 0; i < number; i++)
    {
        scanf("%d %d %d", &meteor[i].x, &meteor[i].y, &meteor[i].time);
    }

    BFS bfs(meteor, number);

    bfs.bfs();

    printf("%d\n", bfs.result);
    return 0;
}