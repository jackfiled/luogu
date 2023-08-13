#include <cstdio>
#include <cstring>

int main()
{
    char output[2000][2000];
    memset(output, ' ', sizeof(output));

    int number;
    scanf("%d", &number);

    // 初始化图腾
    output[0][1] = '/';
    output[0][2] = '\\';
    output[1][0] = '/';
    output[1][1] = '_';
    output[1][2] = '_';
    output[1][3] = '\\';
    int width = 4, height = 2;

    for (int i = 1; i < number; i++)
    {
        // 首先向下平移、向右复制
        for (int h = 0; h < height; h++)
        {
            for (int w = 0; w < width; w++)
            {
                output[height + h][w] = output[h][w];
                output[height +h][width + w] = output[h][w];
                // 同时清空
                output[h][w] = ' ';
            }
        }

        // 然后向上复制
        for (int h = 0; h < height; h++)
        {
            for (int w = 0; w < width; w++)
            {
                output[h][w + width / 2] = output[height + h][w];
            }
        }

        // 计算现在的宽高
        width = width * 2;
        height = height * 2;
    }

    // 打印图形
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            printf("%c", output[h][w]);
        }
        printf("\n");
    }

    return 0;
}