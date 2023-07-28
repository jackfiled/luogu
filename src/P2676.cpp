#include <algorithm>
#include <functional>
#include <cstdio>

using namespace std;

int main()
{
    int number, target;
    scanf("%d %d", &number, &target);
    int cows[number];

    for (int i = 0; i < number; i++)
    {
        scanf("%d", &cows[i]);
    }

    sort(cows, cows + number, greater<int>());

    int count = 0;
    int sum = 0;
    for (int i = 0; i < number; i++)
    {
        sum = sum + cows[i];
        count++;
        if (sum >= target)
        {
            break;
        }
    }
    printf("%d\n", count);

    return 0;
}