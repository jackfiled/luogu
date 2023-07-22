#include <cstdio>

int main()
{
    int number, time;
    scanf("%d %d", &number, &time);

    // 全部坐标加1 同题目要求保持一致
    int matrix[number + 1][number + 1];

    int n = 1;
    for (int i = 1; i <= number; i++)
    {
        for (int j = 1; j <= number; j++)
        {
            matrix[i][j] = n;
            n++;
        }
    }

    // 存储中间结果的临时矩阵
    int temp[number + 1][number + 1];

    for (int t = 0; t < time; t++)
    {
        int x, y, r, z;
        scanf("%d %d %d %d", &x, &y, &r, &z);

        if (z == 0)
        {
            // 顺时针
            // 2,2|2,3|2,4 -> 2,4|3,4|4,4
            for (int i = 0; i < 2 * r + 1; i++)
            {
                for (int j = 0; j < 2 * r + 1; j++)
                {
                    temp[x - r + j][y + r - i] = matrix[x - r + i][y - r + j];
                }
            }

            // 将旋转的结果复制到矩阵中
            for(int i = x - r; i <= x + r; i++)
            {
                for (int j = y - r; j <= y + r; j++)
                {
                    matrix[i][j] = temp[i][j];
                }
            }
        }
        else
        {
            // 逆时针
            // 2,2|2,3|2,4 -> 4,2|3,2|2,2
            for (int i = 0; i < 2 * r + 1; i++)
            {
                for (int j = 0; j < 2 * r + 1; j++)
                {
                    temp[x + r - j][y - r + i] = matrix[x - r + i][y - r + j];
                }
            }

            // 同上
            for(int i = x - r; i <= x + r; i++)
            {
                for (int j = y - r; j <= y + r; j++)
                {
                    matrix[i][j] = temp[i][j];
                }
            }
        }
    }

    for (int i = 1; i <= number; i++)
    {
        for (int j = 1; j <= number; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}