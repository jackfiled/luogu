#include <cstdio>

char target[] = "yizhong";
int direction[][2] = {{0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}};

class DFS
{
public:
    char matrix[100][100];
    bool result[100][100];
    int number;

    void init()
    {
        for (int i = 0; i < number; i++)
        {
            for (int j = 0; j < number; j++)
            {
                result[i][j] = false;
            }
        }
    }


    void dfs(int x, int y, int dir[], int pos)
    {
        if (pos == 7)
        {
            for (int i = 1; i <= 7; i++)
            {
                result[x - dir[0] * i][y - dir[1] * i] = true;
            }
            return;
        }

        int nextX = x + dir[0];
        int nextY = y + dir[1];

        if (matrix[x][y] == target[pos])
        {
            if ((nextX >= 0 and nextX < number and nextY >= 0 and nextY < number) or pos == 6)
            {
                dfs(nextX, nextY, dir, pos + 1);
            }
        }
    }
};

int main()
{
    DFS dfs;
    scanf("%d\n", &dfs.number);
    dfs.init();

    char input[110];
    for (int i = 0; i < dfs.number; i++)
    {
        fgets(input, 110, stdin);

        for (int j = 0; j < dfs.number; j++)
        {
            dfs.matrix[i][j] = input[j];
        }
    }

    for (int i = 0; i < dfs.number; i++)
    {
        for (int j = 0; j < dfs.number; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                int nextX = i + direction[k][0];
                int nextY = j + direction[k][1];

                if (dfs.matrix[i][j] == target[0] and dfs.matrix[nextX][nextY] == target[1])
                {
                    dfs.dfs(i, j, direction[k], 0);
                }
            }
        }
    }

    for (int i = 0; i < dfs.number; i++)
    {
        for (int j = 0; j < dfs.number; j++)
        {
            if (dfs.result[i][j])
            {
                printf("%c", dfs.matrix[i][j]);
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}