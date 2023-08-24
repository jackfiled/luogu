#include <cstdio>

int main()
{
    int length, number, target;
    scanf("%d %d %d", &length, &number, &target);

    int flags[number];
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &flags[i]);
    }

    int left = 0;
    int right = length;

    int result = -1;
    while (left <= right)
    {
        int middle = (left + right) / 2;

        int n = target;
        int now = 0;
        for (int i = 1; i < number;)
        {
            if (n < 0)
            {
                break;
            }

            if (flags[i] - now <= middle)
            {
                now = flags[i];
                i++;
            }
            else
            {
                now = now + middle;
                n--;
            }
        }

        if (n >= 0)
        {
            right = middle - 1;
            result = middle;
        }
        else
        {
            left = middle + 1;
        }
    }

    printf("%d\n", result);
    return 0;
}