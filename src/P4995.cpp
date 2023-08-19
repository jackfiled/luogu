#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int number;
    scanf("%d", &number);

    int height[number];
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &height[i]);
    }

    sort(height, height + number);

    long long result = pow(height[number - 1], 2);

    int i = 0, j = number - 1;

    while(i < j)
    {
        result += pow(height[j] - height[i], 2);
        j--;

        if (i == j)
        {
            break;
        }

        result += pow(height[i] - height[j], 2);
        i++;
    }

    printf("%lld\n", result);
    return 0;
}