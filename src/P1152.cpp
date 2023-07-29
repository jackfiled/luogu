#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int number;
    scanf("%d", &number);

    int array[number - 1];

    int first, second;
    scanf("%d", &first);
    for (int i = 0; i < number - 1; i++)
    {
        scanf("%d", &second);
        array[i] = abs(first - second);
        first = second;
    }

    sort(array, array + number - 1);

    bool flag = true;
    for (int i = 0; i < number - 1; i++)
    {
        if (array[i] != i + 1)
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        printf("Jolly\n");
    }
    else
    {
        printf("Not jolly\n");
    }
    return 0;
}