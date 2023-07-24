#include <cstdio>
#include <vector>

using namespace std;

vector<int> multiplxInt(vector<int>& number, int n)
{
    vector<int> result;
    int overflow = 0;

    // 这里认为number默认是从低位开始
    for (auto i = number.begin(); i != number.end(); i++)
    {
        int multiplx = (*i) * n + overflow;
        result.push_back(multiplx % 10);
        overflow = multiplx / 10;
    }

    if (overflow != 0)
    {
        while(overflow != 0)
        {
            result.push_back(overflow % 10);
            overflow = overflow / 10;
        }
    }

    return result;
}

vector<int> factor(int n)
{
    int i = 2;
    int sum = 0;
    vector<int> result;

    while(n - sum >= i)
    {
        sum = sum + i;
        result.push_back(i);
        i++;
    }

    // 最后的余数
    int delta = n - sum;

    // 余数等于0还是不要处理了，，，
    bool flag = delta != 0;
    while(flag)
    {
        for (auto i = result.rbegin(); i != result.rend(); i++)
        {
            (*i)++;
            delta--;
            if (delta == 0)
            {
                flag = false;
                break;
            }
        }
    }

    return result;
}

int main()
{
    int number;
    scanf("%d", &number);

    vector<int> result = factor(number);

    for (auto i = result.begin(); i != result.end(); i++)
    {
        printf("%d ", *i);
    }
    printf("\n");

    vector<int> sum;
    sum.push_back(*result.begin());

    for (auto i = result.begin() + 1; i != result.end(); i++)
    {
        sum = multiplxInt(sum, *i);
    }    

    for (auto i = sum.rbegin(); i != sum.rend(); i++)
    {
        printf("%d", *i);
    }
    printf("\n");

    return 0;
}