#include <cstdio>

int main()
{
    int number, target;
    scanf("%d %d", &number, &target);

    int trees[number];
    long long sum = 0;
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &trees[i]);
        sum += trees[i];
    }

    int left = 0;
    int right = sum / target;

    if (right == 0)
    {
        printf("0\n");
        return 0;
    }

    while (left + 1 < right)
    {
        int middle = (left + right) / 2;

        int n = 0;
        for (int i = 0; i < number; i++)
        {
            n += trees[i] / middle;
        }

        if (n >= target)
        {
            left = middle;
        }
        else
        {
            right = middle;
        }
    }

    int n = 0;
    for (int i = 0; i < number; i++)
    {
        n += trees[i] / right;
    }
    if (n >= target)
    {
        printf("%d\n", right);
    }
    else
    {
        printf("%d\n", left);
    }

    return 0;
}