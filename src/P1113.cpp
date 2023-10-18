#include <cstdio>
#include <memory>

int main()
{
    int number;
    scanf("%d", &number);

    int points[number + 1] = {0};

    int result = 0;
    for (int i = 1; i <= number; i++)
    {
        int p, t;
        scanf("%d %d", &p, &t);
        
        int tmp = 0;
        while (true)
        {
            int n;
            scanf("%d", &n);

            if (n == 0)
            {
                break;
            }

            tmp = points[n] > tmp ? points[n] : tmp;
        }

        points[i] = tmp + t;

        result = points[i] > result ? points[i] : result;
    }

    printf("%d\n", result);
    return 0;
}