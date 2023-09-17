#include <cstdio>

bool is_prime(int& number)
{
    if (number == 1)
    {
        return false;
    }

    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int number;
    scanf("%d", &number);

    for (int c = 0; c < number; c++)
    {
        int i, j;
        scanf("%d %d", &i, &j);

        bool matrix[i][j];

        for (int i0 = 0; i0 < i; i0++)
        {
            for (int j0 = 0; j0 < j; j0++)
            {
                int n;
                scanf("%d", &n);
                matrix[i0][j0] = is_prime(n);
            }
        }

        for (int i0 = 0; i0 < i; i0++)
        {
            for (int j0 = 0; j0 < j; j0++)
            {
                int result = 0;

                int k = i0;
                while(k >= 0 and matrix[k][j0])
                {
                    k--;
                    result++;
                }
                printf("%d ", result);
            }
            printf("\n");
        }
    }

    return 0;
}