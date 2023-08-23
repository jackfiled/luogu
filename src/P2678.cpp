#include <cstdio>

int main()
{
    int length, number, m;
    scanf("%d %d %d", &length, &number, &m);

    int stone[number + 1];
    stone[number] = length;
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &stone[i]);
    }

    int left = 1, right = length;

    int result = -1;
    while (left <= right)
    {
        int middle = (left + right) / 2;

        int n = 0, now = -1;

        for (int i = 0; i <= number; i++)
        {
            if (now == -1)
            {
                if (stone[i] < middle)
                {
                    n++;
                }
                else
                {
                    now = i;
                }
            }
            else
            {
                if (stone[i] - stone[now] < middle)
                {
                    n++;
                }
                else
                {
                    now = i;
                }
            }
        }

        if (n > m)
        {
            right = middle - 1;
        }
        else
        {
            result = middle;
            left = middle + 1;
        }
    }

    printf("%d\n", result);
    return 0;
}