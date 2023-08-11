#include <cstdio>
#include <cstring>

int main()
{
    char input[40];
    long long index;
    scanf("%s %lld", input, &index);
    long long length = strlen(input);

    while (index > length)
    {
        // 求index所在串的长度
        long long i = length;

        while (index > i)
        {
            i = i * 2;
        }
        i = i / 2;
        // 移动到下一个字串中的位置
        index = index - i - 1;
        if (index == 0)
        {
            index = i;
        }
    }

    printf("%c\n", input[index - 1]);
    return 0;
}