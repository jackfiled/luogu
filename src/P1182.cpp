#include <cstdio>

int main()
{
    int number, target;
    scanf("%d %d", &number, &target);

    int array[number];
    int sum = 0;
    int max = -1;
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &array[i]);
        sum += array[i];
        max = array[i] > max ? array[i] : max;
    }

    int left = max;
    int right = sum;

    while (left <= right)
    {
        int middle = (left + right) / 2;

        int segement = 0;
        int sum = 0;

        for (int i = 0; i < number; i++)
        {
            int temp = sum + array[i];
            if (temp > middle)
            {
                segement++;
                sum = array[i];
            }
            else
            {
                sum = temp;
            }
        }

        if (segement >= target)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }

    printf("%d\n", left);
    return 0;
}