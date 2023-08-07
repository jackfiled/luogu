#include <cstdio>

long long mod = 1e9 + 7;

long long Combination(long long n, long long m)
{
    // 由于此处m只可能为1或者2 
    if (m == 1ll)
    {
        return n % mod;
    }
    else
    {
        return (n * (n - 1ll) / 2ll) % mod;
    }
}

int main()
{
    int number;
    scanf("%d", &number);

    long long length[5001] = {0};

    for (int i = 0; i < number; i++)
    {
        int temp;
        scanf("%d", &temp);
        length[temp]++;
    }

    long long result = 0;
    for (int i = 1; i <= 5000; i++)
    {
        if (length[i] < 2)
        {
            continue;
        }

        // 两个相同长度木棍的种类
        int t = Combination(length[i], 2);
        for (int j = 1; j <= i / 2; j++)
        {
            if (j != i - j)
            {
                // 选择了两条不等宽的木棍
                if (length[i - j] >= 1ll and length[j] >= 1ll)
                {
                    result += t * Combination(length[i - j], 1ll) * Combination(length[j], 1ll) % mod;
                }
            }
            else
            {
                // 选择了两条等宽的木棍
                if (length[j] >= 1ll)
                {
                    result += t * Combination(length[j], 2ll) % mod;
                }
            }
            result = result % mod;
        }
    }

    printf("%lld\n", result);
    return 0;
}