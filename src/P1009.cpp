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

vector<int> multipleSingle(vector<int>& n, int m)
{
    vector<int> middle;
    int overflow = 0;
    for (auto i = n.begin(); i != n.end(); i++)
    {
        int multiplx = (*i) * m + overflow;
        middle.push_back(multiplx % 10);
        overflow = multiplx / 10;
    }

    if (overflow != 0)
    {
        middle.push_back(overflow);
    }

    return middle;
}

int main()
{
    int number;
    scanf("%d", &number);

    vector<int> result;
    result.push_back(1);
    vector<int> middle(result);

    for (int i = 2; i <= number; i++)
    {   
        // 个位上的结果
        vector<int> temp1 = multipleSingle(middle, i % 10);

        // 下面计算十位上的结果
        // 这里只考虑i < 100 的情况
        if (i >= 10)
        {
            vector<int> temp10(middle);
            temp10.insert(temp10.begin(), 0);
            temp10 = multipleSingle(temp10, i / 10);
            middle = add(temp1, temp10);
        }
        else
        {
            middle = temp1;
        }
        
        result = add(result, middle);
    }

    for (auto itor = result.rbegin(); itor != result.rend(); itor++)
    {
        printf("%d", *itor);
    }
    printf("\n");

    return 0;
}