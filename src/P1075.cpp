#include <cstdio>

using namespace std;

int main()
{
    int input;
    scanf("%d", &input);

    for (int i = 2; i < input; i++)
    {
        if (input % i == 0)
        {
            // 找到最小的因数
            printf("%d\n", input / i);
            break;
        }
    }

    return 0;
}