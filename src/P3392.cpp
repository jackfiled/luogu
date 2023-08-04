#include <cstdio>

struct Line {
    int Red = 0;
    int White = 0;
    int Blue = 0;
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int count = 0;
    Line lines[n];
    while (true)
    {
        char input = getchar();
        switch (input)
        {
            case 'R':
                lines[count / m].Red++;
                count++;
                break;
            case 'W':
                lines[count / m].White++;
                count++;
                break;
            case 'B':
                lines[count / m].Blue++;
                count++;
                break;
            default:
                break;
        }

        if (count == n * m)
        {
            break;
        }
    }

    // 显然
    // 第一行必为白色
    // 最后一行必为红色
    // 因此只考虑中间的部分
    int base = lines[0].Blue + lines[0].Red + lines[n - 1].Blue + lines[n - 1].White;
    int result = 1 << 30;
    for (int blueLine = 1; blueLine <= n - 2; blueLine++)
    {
        // 蓝色行至少为1行，至多为n - 2行
        for (int whiteLine = 0; whiteLine <= n - 2 - blueLine; whiteLine++)
        {
            // 白色行可以没有

            int need = base;
            // 计算白色的部分
            for (int i = 1; i < 1 + whiteLine; i++)
            {
                need = need + lines[i].Blue + lines[i].Red;
            }

            // 计算蓝色的部分
            for (int i = 1 + whiteLine; i < 1 + whiteLine + blueLine; i++)
            {
                need = need + lines[i].Red + lines[i].White;
            }

            // 计算红色的部分
            for (int i = 1 + whiteLine + blueLine; i < n - 1; i++)
            {
                need = need + lines[i].Blue + lines[i].White;
            }

            result = need < result ? need : result;
        }
    }
    
    printf("%d\n", result);
    return 0;
}