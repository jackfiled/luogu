#include <cstdio>

int main()
{
    int number;
    scanf("%d", &number);

    int result = 0,last = 0;
    for (int i = 0; i < number; i++)
    {
        int x;
        scanf("%d", &x);

        if (x > last)
        {
            result += x - last;
        }
        last = x;
    }
    
    printf("%d\n", result);
    return 0;
}