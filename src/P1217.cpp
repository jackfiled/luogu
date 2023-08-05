#include <cstdio>
#include <string>

using namespace std;

// 是否为回文数
bool isPalindromes(int i)
{
    string number = to_string(i);
    
    for (auto begin = number.begin(), end = --number.end(); begin != end; begin++, end--)
    {
        if (*begin != *end)
        {
            return false;
        }
    }

    return true;
}

bool isPrime(int number)
{
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int begin, end;
    scanf("%d %d", &begin, &end);

    begin = begin % 2 == 0 ? begin + 1 : begin;

    for (int i = begin; i <= end; i = i + 2)
    {
        // 11是特例
        if (i == 11)
        {
            printf("%d\n", 11);
        }

        // 首先判断i的位数不能为偶数
        if ((i >= 10 and i <= 100) or (i >= 1000 and i <= 10000) or (i >= 100000 and i <= 1000000)
            or (i >= 10000000 and i <= 100000000))
        {
            continue;
        }

        // 然后判断回文
        if (!isPalindromes(i))
        {
            continue;
        }

        // 最后是质数
        if (isPrime(i))
        {
            printf("%d\n", i);
        }
    }

    return 0;
}