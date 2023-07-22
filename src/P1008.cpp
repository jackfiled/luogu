#include <cstdio>
#include <string>

using namespace std;

bool judge(int a, int b, int c)
{
    bool numbers[9] = {false};
    int input[3] = {a, b, c};

    for (int i = 0; i < 3; i++)
    {
        int number = input[i];

        if (numbers[number / 100 - 1])
        {
            return false;
        }
        numbers[number / 100 - 1] = true;

        number = number % 100;

        if (numbers[number / 10 - 1])
        {
            return false;
        }
        numbers[number / 10 - 1] = true;

        number = number % 10;

        if (numbers[number - 1])
        {
            return false;
        }
        numbers[number - 1] = true;
    }

    return true;
}

int main()
{
    for (int a = 123; a < 333; a++)
    {
        int b = a * 2;
        int c = a * 3;

        if (judge(a, b, c))
        {
            printf("%d %d %d\n", a, b, c);
        }
    }

    return 0;
}