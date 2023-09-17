#include <cstdio>

int main()
{
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);

    if (a + b == c)
    {
        printf("plus\n");
    }
    else if (a - b == c)
    {
        printf("minus\n");
    }
    else
    {
        printf("illegal\n");
    }

    return 0;
}