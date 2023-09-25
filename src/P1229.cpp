#include <cstdio>
#include <cstring>

int main()
{
    char str1[100];
    char str2[100];
    scanf("%s", str1);
    scanf("%s", str2);

    long long result = 0;
    for (size_t i = 0; i < strlen(str1); i++)
    {
        for (size_t j = 1; j < strlen(str2); j++)
        {
            if (str1[i] == str2[j] and str1[i + 1] == str2[j - 1])
            {
                result++;
            }
        }
    }

    printf("%lld\n", (long long)1 << result);
    return 0;
}