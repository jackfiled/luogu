#include <cstdio>

int main()
{
    int target;
    scanf("%d", &target);

    double sum = 0;
    for (int i = 1; ; i++)
    {
        sum = sum + 1.0 / (double)i;
        
        if (sum > target)
        {
            printf("%d\n", i);
            return 0;
        }
    }

    return 0;
}