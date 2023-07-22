#include <cstdio>
#include <vector>

using namespace std;

vector<int> add(vector<int> &aNumber, vector<int> &bNumber)
{
    vector<int> result;
    int overflow = 0;
    auto aItor = aNumber.begin();
    auto bItor = bNumber.begin();
    while (aItor != aNumber.end() or bItor != bNumber.end())
    {
        int sum = overflow;
        overflow = 0;
        if (aItor != aNumber.end())
        {
            sum += *aItor;
            aItor++;
        }

        if (bItor != bNumber.end())
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

    return result;
}

int main()
{
    char a[2000], b[2000];
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

    // 处理乘数为0的情况
    if ((aNumber.size() == 1 and aNumber[0] == 0) or (bNumber.size() == 1 and bNumber[0] == 0))
    {
        printf("0\n");
        return 0;
    }

    vector<int> result;
    // 次数
    int count = 0;
    for (auto aItor = aNumber.rbegin(); aItor != aNumber.rend(); aItor++, count++)
    {
        vector<int> middle;
        int overflow = 0;
        for (auto bItor = bNumber.rbegin(); bItor != bNumber.rend(); bItor++)
        {
            int mulitplx = (*aItor) * (*bItor) + overflow;
            middle.push_back(mulitplx % 10);
            overflow = mulitplx / 10;
        }

        if (overflow != 0)
        {
            middle.push_back(overflow);
        }

        for (int i = 0; i < count; i++)
        {
            middle.insert(middle.begin(), 0);
        }
        result = add(result, middle);
    }

    for (auto i = result.rbegin(); i != result.rend(); i++)
    {
        printf("%d", *i);
    }
    printf("\n");
    return 0;
}