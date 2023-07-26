#include <random>
#include <vector>
#include <cstdio>

using namespace std;

#define randint(l, r) rand() % (r - l + 1) + l

int a[100001], b[100001], c[100001];

void qsort(int *array, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    
    int middle = array[randint(l ,r)];
    int aIndex =0, bIndex = 0, cIndex = 0;

    for (int i = l; i <= r; i++)
    {
        int temp = array[i];

        if (temp < middle)
        {
            a[aIndex] = temp;
            aIndex++;
        }
        else if (temp == middle)
        {
            b[bIndex] = temp;
            bIndex++;
        }
        else
        {
            c[cIndex] = temp;
            cIndex++;
        }
    }

    for (int i = 0; i < aIndex; i++)
    {
        array[l + i] = a[i];
    }
    for (int i = 0; i < bIndex; i++)
    {
        array[l + aIndex + i] = b[i];
    }
    for (int i = 0; i < cIndex; i++)
    {
        array[l + aIndex + bIndex + i] = c[i];
    }

    qsort(array, l, l + aIndex - 1);
    qsort(array, l + aIndex + bIndex, r);
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

    qsort(array, 0, number - 1);

    for (int i = 0; i < number; i++)
    {
        if (i == number - 1)
        {
            printf("%d\n", array[i]);
        }
        else
        {
            printf("%d ", array[i]);
        }
    }

    return 0;
}