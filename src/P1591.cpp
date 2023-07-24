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

vector<int> factorial(int n)
{
    vector<int> result;
    
    // 1! = 1
    result.push_back(1);

    for (int i = 2; i <= n; i++)
    {
        result = multiplxInt(result, i);
    }

    return result;
}

int main()
{
    int number;
    scanf("%d", &number);

    for (int i = 0; i < number; i++)
    {
        int n, target;

        scanf("%d %d", &n, &target);

        vector<int> result = factorial(n);

        int count = 0;
        for (int i : result)
        {
            if (i == target)
            {
                count++;
            }
        }
        printf("%d\n", count);
    }
}