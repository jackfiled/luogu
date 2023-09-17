#include <cstdio>

int main()
{
    int number;
    scanf("%d", &number);

    for (int l = 0; l < number; l++)
    {
        int n, a, b, c, d, e, f;
        scanf("%d %d %d %d %d %d %d", &n, &a, &b, &c, &d, &e, &f);

        int result = 0;

        if (a < d)
        {
            for (int h = a + 1; h < d; h++)
            {
                for (int m = 0; m < h + 1; m++)
                {
                    result = result + 10 * m + 1;
                }
            }
        }
        else if (a > d)
        {
            for (int h = a + 1; h < n; h++)
            {
                for (int m = 0; m < h + 1; m++)
                {
                    result = result + 10 * m + 1;
                }
            }

            for (int h = 0; h < d; h++)
            {
                for (int m = 0; m < h + 1; m++)
                {
                    result = result + 10 * m + 1;
                }
            }
        }

        if (a == d and b < e)
        {
            for (int m = b + 1; m < e; m++)
            {
                result = result + 10 * m + 1;
            }
        }
        else
        {
            for (int m = b + 1; m < a + 1; m++)
            {
                result = result + 10 * m + 1;
            }

            for (int m = 0; m < e; m++)
            {
                result = result + 10 * m + 1;
            }
        }

        if (a == d and b == e and c < f)
        {
            for (int s = c; s < f; s++)
            {
                result++;
            }
        }
        else
        {
            for (int s = c + 1; s < 10 * b + 1; s++)
            {
                result++;
            }

            for (int s = 0; s < f; s++)
            {
                result++;
            }
        }

        printf("%d\n", result + 1);
    }

    return 0;
}