#include <cstdio>

int main()
{
    int number, x;
    scanf("%d %d", &number, &x);

    int candies[number];

    for (int i = 0; i < number; i++)
    {
        scanf("%d", &candies[i]);
    }

    long long result = 0;
    for (int i = 1; i < number; i++)
    {
        if (candies[i - 1] + candies[i] > x)
        {
            result += candies[i - 1] + candies[i] - x;
            //candies[i] = candies[i] - (candies[i] + candies[i - 1] - x);
            candies[i] = x - candies[i - 1];
            if (candies[i] < 0)
            {
                candies[i - 1] = candies[i - 1] + candies[i];
                candies[i] = 0;
            }
        }
    }

    printf("%lld\n" ,result);
    return 0;
}