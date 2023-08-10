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
    int begin, end;
    scanf("%d %d", &begin, &end);

    vector<int> f1, f2;
    f1.push_back(1);
    f2.push_back(1);
    for(int i = begin; i < end - 1; i++)
    {
        vector<int> result = add(f1, f2);
        f1 = f2;
        f2 = result;
    }

    if (end - begin == 1)
    {
        printf("1\n");
    }
    else
    {
        for (auto i = f2.rbegin(); i < f2.rend(); i++)
        {
            printf("%d", *i);
        }
        printf("\n");
    }

    return 0;
}