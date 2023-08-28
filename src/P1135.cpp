#include <cstdio>
#include <queue>

using namespace std;

class BFS
{
public:
    int result = -1;

    BFS(int number, int *floors)
    {
        this->number = number;
        this->floors = floors;

        visit = new bool[number + 1];
        for (int i = 1; i <= number; i++)
        {
            visit[i] = false;
        }
    }

    ~BFS()
    {
        delete[] visit;
    }

    void bfs(int begin, int end)
    {
        q.push(make_pair(begin, 0));

        while(!q.empty())
        {
            auto head = q.front();
            q.pop();

            if (head.first == end)
            {
                result = head.second;
                break;
            }

            int up = head.first + floors[head.first];
            if (up >= 1 and up <= number and !visit[up])
            {
                q.push(make_pair(up, head.second + 1));
                visit[up] = true;
            }

            int down = head.first - floors[head.first];
            if (down >= 1 and down <= number and !visit[down])
            {
                q.push(make_pair(down, head.second + 1));
                visit[down] = true;
            }
        }
    }

private:
    int *floors;
    int number;

    bool *visit;
    queue<pair<int, int>> q;
};

int main()
{
    int number, begin, end;
    scanf("%d %d %d", &number, &begin, &end);

    int floors[number + 1];
    for (int i = 1; i <= number; i++)
    {
        scanf("%d", &floors[i]);
    }

    BFS bfs(number, floors);

    bfs.bfs(begin, end);

    printf("%d\n", bfs.result);

    return 0;
}