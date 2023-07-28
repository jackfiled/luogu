#include <cstdio>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int number;
    scanf("%d", &number);

    int array[number];
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &array[i]);
    }

    int swapCount = 0;
    for (int i = 0; i < number - 1; i++)
    {
        for (int j = number - 1; j > i; j--)
        {
            if (array[j - 1] > array[j])
            {
                swap(&array[j - 1], &array[j]);
                swapCount++;
            }
        }
    }

    printf("%d\n", swapCount);
    return 0;
}