#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int number, time;
    scanf("%d", &number);
    scanf("%d", &time);

    int array[number];

    for (int i = 0; i < number; i++)
    {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < time; i++)
    {
        next_permutation(array, array + number);
    }

    for (int i = 0; i < number; i++)
    {
        if (i == number - 1)
        {
            printf("%d", array[i]);
        }
        else
        {
            printf("%d ", array[i]);
        }
    }
    printf("\n");
}