#include <cstdio>

int main()
{
    int r, c, k;
    scanf("%d %d %d", &r, &c, &k);
    char playground[r][c];

    int count = 0;
    while (true)
    {
        char input = getchar();
        switch(input)
        {
            case '.':
                playground[count / c][count % c] = 0;
                count++;
                break;
            case '#':
                playground[count / c][count % c] = 1;
                count++;
                break;
            default:
                break;
        }

        if (count == r * c)
        {
            break;
        }
    }

    int result = 0;
    // 首先计算一下横着站
    for (int i = 0; i < r; i++)
    {
        int space = 0;
        for (int j = 0; j < c; j++)
        {
            if (playground[i][j] == 0)
            {
                space++;
            }
            else
            {
                space = 0;
            }

            if (space == k)
            {
                result++;
                j = j - space + 1;
                space = 0;
            }
        }
    }

    if (k == 1)
    {
        // 横着站和竖着站是一样的
        printf("%d\n", result);
        return 0;
    }

    // 然后计算一下竖着站
    for (int i = 0; i < c; i++)
    {
        int space = 0;
        for (int j = 0; j < r; j++)
        {
            if (playground[j][i] == 0)
            {
                space++;
            }
            else
            {
                space = 0;
            }

            if (space == k)
            {
                result++;
                j = j - space + 1;
                space = 0;
            }
        }
    }

    printf("%d\n", result);

    return 0;
}