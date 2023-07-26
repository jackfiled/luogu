#include <cstdio>
#include <cstdlib>

int array[5000000];
int target;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void qsort(int l ,int r)
{
    int i = l, j = r, mid = array[(l + r) /2];
    do
    {
        while(array[j] > mid)
        {
            j--;
        }
        while(array[i] < mid)
        {
            i++;
        }

        if (i <= j)
        {
            swap(&array[i], &array[j]);
            i++;
            j--;
        }
    }
    while(i <= j);

    if (target <= j)
    {
        // 目标在左区间
        qsort(l, j);
    }
    else if (target >= i)
    {
        // 目标在右区间
        qsort(i, r);
    }
    else
    {
        // 目标在中间区间
        printf("%d\n", array[j + 1]);
        exit(0);
    }
}

int main()
{
    int number;
    scanf("%d %d", &number, &target);
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &array[i]);
    }
    qsort(0, number - 1);
    return 0;
}