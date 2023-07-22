#include <cstdio>
#include <cstring>

int main()
{
    int height, width;
    scanf("%d %d", &height, &width);
    // 吃掉scanf没有干掉的\n
    getchar();

    int ground[height + 2][width + 2];
    memset(ground, 0, sizeof(int) * (height + 2) * (width + 2));

    int w = 1;
    int h = 1;
    while (h <= height)
    {
        char c = getchar();

        switch (c)
        {
        case '*':
            ground[h][w] = -1;
            w++;
            break;
        case '?':
            w++;
            break;
        case '\n':
            w = 1;
            h++;
            break;
        default:
            break;
        }
    }

    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            if (ground[i][j] != -1)
            {
                int result = ground[i - 1][j - 1] + ground[i - 1][j] + ground[i - 1][j + 1]
                    + ground[i][j - 1] + ground[i][j + 1]
                    + ground[i + 1][j - 1] + ground[i + 1][j] + ground[i + 1][j + 1];
                printf("%d", -result);
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