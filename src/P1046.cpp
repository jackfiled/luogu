#include <cstdio>

int main()
{
    int height[10];

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &height[i]);
    }

    int taotao;
    scanf("%d", &taotao);
    taotao = taotao + 30;

    int result = 0;
    for (int i = 0; i < 10; i++)
    {
        if (taotao >= height[i])
        {
            result++;
        }
    }
    printf("%d\n", result);
    
    return 0;
}