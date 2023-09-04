#include <cstdio>

int delta[][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

class DFS
{
public:
    int height, width;
    char field[150][150];
    bool visit[150][150];

    void init()
    {
        for (int i = 0; i < height; i++)
        {
            char input[200];
            fgets(input, 200, stdin);

            for (int j = 0; j < width; j++)
            {
                field[i][j] = input[j];
                visit[i][j] = false;
            }
        }
    }

    void dfs(int x, int y)
    {
        if (field[x][y] == 'W')
        {
            visit[x][y] = true;

            for (int i = 0; i < 8; i++)
            {
                int tempX = x + delta[i][0], tempY = y + delta[i][1];
                if (check(tempX, tempY))
                {
                    dfs(tempX, tempY);
                }
            }
        }
    }

private:
    bool check(int x, int y)
    {
        if (x >= 0 and x < height and y >= 0 and y < width)
        {
            if (field[x][y] == 'W' and !visit[x][y])
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    DFS dfs;

    scanf("%d %d\n", &dfs.height, &dfs.width);

    dfs.init();
    int result = 0;

    for (int i = 0; i < dfs.height; i++)
    {
        for (int j = 0; j < dfs.width; j++)
        {
            if (dfs.field[i][j] == 'W' and !dfs.visit[i][j])
            {
                dfs.dfs(i, j);
                result++;
            }
        }
    }
    
    printf("%d\n", result);
    return 0;
}