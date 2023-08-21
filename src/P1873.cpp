#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int number, target;
    scanf("%d %d", &number, &target);
    int array[number];

    int max = 0;
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &array[i]);
        max = array[i] > max ? array[i] : max;
    }

    sort(array, array + number);

    int left = 0, right = max;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        long long sum = 0;

        for (int i = 0; i < number; i++)
        {
            if (array[i] >= mid)
            {
                sum += array[i] - mid;
            }
        }

        if (sum < target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    printf("%d\n", right);

    return 0;
}