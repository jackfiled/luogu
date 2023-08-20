#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int number, n;
    scanf("%d %d", &number, &n);

    int array[number];
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int target;
        scanf("%d", &target);
        int* pos = lower_bound(array, array + number, target);
        
        if (*pos == target)
        {
            printf("%ld ", pos - array + 1);
        }
        else
        {
            printf("-1 ");
        }
    }

    printf("\n");
    return 0;
}