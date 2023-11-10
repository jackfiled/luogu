#include <cstdio>
#include <cstring>

int main()
{
    int n;
    scanf("%d", &n);

    int students[n + 1];

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &students[i]);
    }

    int left[n + 1];
    int right[n + 1];
    for (int i = 1; i <= n; i++)
    {
        left[i] = 1;
        right[i] = 1;
    }

    // 求在指定同学左边的最长单调升序列长度
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i - 1; j++)
        {
            if (students[i] > students[j] and left[i] < left[j] + 1)
            {
                left[i] = left[j] + 1;
            }
        }
    }

    // 求在指定同学右边的最长单调降序列长度
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (students[i] > students[j] and right[i] < right[j] + 1)
            {
                right[i] = right[j] + 1;
            }
        }
    }

    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        // -1是因为把自己算了两次
        if (left[i] + right[i] - 1 > max)
        {
            max = left[i] + right[i] - 1;
        }
    }
    
    printf("%d\n", n - max);
    return 0;
}