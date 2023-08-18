#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int w, n;
    scanf("%d %d", &w, &n);

    int prices[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &prices[i]);
    }

    sort(prices, prices + n);

    int i = 0, j = n - 1;

    int result = 0;
    while(i <= j)
    {
        if (prices[i] + prices[j] <= w)
        {
            result++;
            i++;
            j--;
        }
        else
        {
            result++;
            j--;
        }
    }

    printf("%d\n", result);
    return 0;
}