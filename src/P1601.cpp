#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    char a[600], b[600];
    scanf("%s", a);
    scanf("%s", b);

    vector<int> aNumber, bNumber;

    for (char *c = a; *c != '\0'; c++)
    {
        aNumber.push_back(*c - 48);
    }

    for (char *c = b; *c != '\0'; c++)
    {
        bNumber.push_back(*c - 48);
    }

    auto aItor = aNumber.rbegin();
    auto bItor = bNumber.rbegin();

    vector<int> result;
    int overflow = 0;
    while (aItor != aNumber.rend() or bItor != bNumber.rend())
    {
        int sum = overflow;
        overflow = 0;
        if (aItor != aNumber.rend())
        {
            sum += *aItor;
            aItor++;
        }

        if (bItor != bNumber.rend())
        {
            sum += *bItor;
            bItor++;
        }

        if (sum >= 10)
        {
            overflow = sum / 10;
            sum = sum % 10;
        }

        result.push_back(sum);
    }
    if (overflow != 0)
    {
        result.push_back(overflow);
    }

    for (auto i = result.rbegin(); i != result.rend(); i++)
    {
        printf("%d", *i);
    }
    printf("\n");

    return 0;
}