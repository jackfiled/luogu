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

vector<int> dp[5001];

int main()
{
    int number;
    scanf("%d", &number);

    dp[0].push_back(0);
    dp[1].push_back(1);
    dp[2].push_back(2);

    for (int i = 3; i <= number; i++)
    {
        dp[i] = add(dp[i - 1], dp[i - 2]);
    }

    for (auto i = dp[number].rbegin(); i < dp[number].rend(); i++)
    {
        printf("%d", *i);
    }
    printf("\n");
    return 0;
}