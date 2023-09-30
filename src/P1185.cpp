#include <cstdio>
#include <cstring>
#include <cmath>

char figure[1000][5000];

void drawTrunk(int x, int y, int deep)
{
    if (x == deep)
    {
        return;
    }

    int leftX = x + 1;
    int leftY = y - 1;

    while (figure[leftX][leftY] != 'o')
    {
        figure[leftX][leftY] = '/';

        leftX = leftX + 1;
        leftY = leftY - 1;
    }
    drawTrunk(leftX, leftY, deep);

    int rightX = x + 1;
    int rightY = y + 1;

    while (figure[rightX][rightY] != 'o')
    {
        figure[rightX][rightY] = '\\';

        rightX = rightX + 1;
        rightY = rightY + 1;
    }
    drawTrunk(rightX, rightY, deep);
}

void drawTree(int height)
{
    // 单独画叶子节点层
    int deep = 3 * pow(2, height - 2);

    int y = 1;
    for (int i = 0; i < pow(2, height - 1); i++)
    {
        figure[deep][y] = 'o';

        if (i % 2 == 0)
        {
            y = y + 4;
        }
        else
        {
            y = y + 2;
        }
    }

    for (int level = 1; level < height; level++)
    {
        int num = pow(2, level - 1);

        int y = 3 * pow(2, height - level + 1 - 2);
        int x = deep - y + 1;
        int distance = y * 2;
        for (int i = 0; i < num; i++)
        {
            figure[x][y] = 'o';
            y = y + distance;
        }
    }

    drawTrunk(1, 3 * pow(2, height - 2), deep);
}

void deleteNode(int x, int y, int deep)
{
    figure[x][y] = ' ';
    if (x == deep)
    {
        return;
    }

    int leftX = x + 1;
    int leftY = y - 1;

    while (figure[leftX][leftY] == '/')
    {
        figure[leftX][leftY] = ' ';

        leftX = leftX + 1;
        leftY = leftY - 1;
    }

    if (figure[leftX][leftY] == 'o')
    {
        deleteNode(leftX, leftY, deep);
    }

    int rightX = x + 1;
    int rightY = y + 1;

    while (figure[rightX][rightY] == '\\')
    {
        figure[rightX][rightY] = ' ';

        rightX = rightX + 1;
        rightY = rightY + 1;
    }

    if (figure[rightX][rightY] == 'o')
    {
        deleteNode(rightX, rightY, deep);
    }
}

int main()
{
    memset(figure, ' ', sizeof(figure));
    int height, number;
    scanf("%d %d", &height, &number);

    drawTree(height);

    int deep = 3 * pow(2, height - 2);
    for (int n = 0; n < number; n++)
    {
        int i, j;
        scanf("%d %d", &i, &j);

        // 一坨大便
        // 但是可以计算出点的坐标
        int y = 3 * pow(2, height - i + 1 - 2);
        int x = deep - y + 1;
        if (x != deep)
        {
            int distance = y * 2;
            for (int l = 0; l < j - 1; l++)
            {
                y = y + distance;
            }
        }
        else
        {
            // 底层的坐标计算不同
            for (int l = 0; l < j - 1; l++)
            {
                if (l % 2 == 0)
                {
                    y = y + 4;
                }
                else
                {
                    y = y + 2;
                }
            }
        }

        if (figure[x][y] == 'o')
        {
            // 删除和父节点之间的连接
            int leftX = x - 1;
            int leftY = y - 1;
            while (figure[leftX][leftY] == '\\')
            {
                figure[leftX][leftY] = ' ';

                leftX = leftX - 1;
                leftY = leftY - 1;
            }

            int rightX = x - 1;
            int rightY = y + 1;
            while (figure[rightX][rightY] == '/')
            {
                figure[rightX][rightY] = ' ';

                rightX = rightX - 1;
                rightY = rightY + 1;
            }

            deleteNode(x, y, deep);
        }
    }

    for (int i = 1; i <= 3 * pow(2, height - 2); i++)
    {
        for (int j = 1; j <= 3 * pow(2, height - 1) - 1; j++)
        {
            printf("%c", figure[i][j]);
        }
        printf("\n");
    }

    return 0;
}