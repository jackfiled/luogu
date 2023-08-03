#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int number;
    scanf("%d", &number);

    int array[number];
    int time = 1;
    for (int i = 0; i < number; i++)
    {
        // 先初始为最大序列
        array[i] = number - i;
        time = time * (i + 1);
    }

    for (int i = 0; i < time; i++)
    {
        next_permutation(array, array + number);

        for (int j = 0; j < number; j++)
        {
            printf("%5d", array[j]);
        }
        printf("\n");
    }

    return 0;
}