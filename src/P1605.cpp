#include <cstdio>

class DFS
{
public:
    int result = 0;
    bool visit[10][10];

    DFS(int width, int height, int endX, int endY)
    {
        this->width = width;
        this->height = height;
        this->endX = endX;
        this->endY = endY;

        for (int i = 1; i <= width; i++)
        {
            for (int j = 1; j <= height; j++)
            {
                field[i][j] = 0;
                visit[i][j] = false;
            }
        }
    }

    void read(int length)
    {
        for (int i = 0; i < length; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);

            field[x][y] = -1;
        }
    }

    void dfs(int nowX, int nowY)
    {
        if (nowX == endX and nowY == endY)
        {
            result++;
            return;
        }

        int upX = nowX, upY = nowY  - 1;
        if (check(upX, upY))
        {
            visit[upX][upY] = true;
            dfs(upX, upY);
            visit[upX][upY] = false;
        }

        int downX = nowX, downY = nowY + 1;
        if (check(downX, downY))
        {
            visit[downX][downY] = true;
            dfs(downX, downY);
            visit[downX][downY] = false;
        }

        int leftX = nowX - 1, leftY = nowY;
        if (check(leftX, leftY))
        {
            visit[leftX][leftY] = true;
            dfs(leftX, leftY);
            visit[leftX][leftY] = false;
        }

        int rightX = nowX + 1, rightY = nowY;
        if (check(rightX, rightY))
        {
            visit[rightX][rightY] = true;
            dfs(rightX, rightY);
            visit[rightX][rightY] = false;
        }
    }

private:
    int field[10][10];
    int width, height;
    int endX, endY;

    bool check(int x, int y)
    {
        if (x < 1 or x > width or y < 1 or y > height)
        {
            return false;
        }

        if (field[x][y] == -1)
        {
            return false;
        }

        if (visit[x][y])
        {
            return false;
        }

        return true;
    }

};

int main()
{
    int width, height, length;
    scanf("%d %d %d", &width, &height, &length);

    int startX, startY, endX, endY;
    scanf("%d %d %d %d", &startX, &startY, &endX, &endY);

    DFS dfs(width, height, endX, endY);

    dfs.read(length);

    dfs.visit[startX][startY] = true;
    dfs.dfs(startX, startY);

    printf("%d\n", dfs.result);

    return 0;
}