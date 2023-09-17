#include <cstdio>

int main()
{
    int number;
    scanf("%d", &number);

    for (int i = 0; i < number; i++)
    {
        int x0, a;
        scanf("%d %d", &x0, &a);

        int last = x0;
        printf("%d ", x0);
        while (true)
        {
            x0 = x0 / a + 1;
            if (x0 == last)
            {
                break;
            }
            printf("%d ", x0);
            last = x0;
        }

        printf("\n");
    }

    return 0;
}