#include <cstdio>

int main()
{
    long long n, m, p, q;
    scanf("%lld %lld %lld %lld", &n, &m, &p, &q);

    long long max = n * m;
    long long target = p * m + q;

    if (target >= max)
    {
        printf("Segmentation fault.\n");
    }
    else
    {
        printf("Program ends with return value 0.\n");
    }

    return 0;
}