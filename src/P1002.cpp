#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

// 这里使用宏定义绕过二维数组传参的难题
#define setHorsePosition(matrix, x, y, borderX, borderY) \
    if (x >= 0 and x < borderX) \
    { \
        if (y >= 0 and y < borderY) \
        { \
            matrix[x][y] = -1; \
        } \
    }

int main()
{
    int bx, by, horsex, horsey;
    scanf("%d %d %d %d", &bx, &by, &horsex, &horsey);
    // 由于棋盘的特性
    bx++;
    by++;

    long long chessboard[bx][by];

    // 将数组中都置0
    memset(chessboard, 0, sizeof(long long) * bx * by);

    // 首先把马可以吃掉的位置标记为-1
    setHorsePosition(chessboard, horsex - 1, horsey - 2, bx, by);
    setHorsePosition(chessboard, horsex + 1, horsey - 2, bx, by);
    setHorsePosition(chessboard, horsex - 1, horsey + 2, bx, by);
    setHorsePosition(chessboard, horsex + 1, horsey + 2, bx, by);
    setHorsePosition(chessboard, horsex + 2, horsey + 1, bx, by);
    setHorsePosition(chessboard, horsex + 2, horsey - 1, bx, by);
    setHorsePosition(chessboard, horsex - 2, horsey + 1, bx, by);
    setHorsePosition(chessboard, horsex - 2, horsey - 1, bx, by);
    setHorsePosition(chessboard, horsex, horsey, bx, by);

    // 使用动态规划的思想解题
    // f(x,y) = f(x - 1, y) + f(x, y - 1)

    for (int i = 0; i < bx; i++)
    {
        for (int j = 0; j < by; j++)
        {
            // 如果是马可以到达的位置
            // f(x, y) = 0
            if (chessboard[i][j] == -1)
            {
                chessboard[i][j] = 0;
                continue;
            }

            // 考虑棋盘边界的情况
            if (i == 0 and j == 0)
            {
                chessboard[i][j] = 1;
            }
            else if(j == 0)
            {
                // 棋盘的左边界
                chessboard[i][j] = chessboard[i - 1][j];
            }
            else if (i == 0)
            {
                // 棋盘的上边界
                chessboard[i][j] = chessboard[i][j - 1];
            }
            else
            {
                chessboard[i][j] = chessboard[i - 1][j] + chessboard[i][j  - 1];
            }
        }
    }

    printf("%lld\n", chessboard[bx - 1][by - 1]);

    return 0;
}