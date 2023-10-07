#include <cstdio>
#include <unordered_map>

using namespace std;

int main()
{
    int number;
    scanf("%d", &number);

    unordered_map<int, int> balls;
    for (int i = 1; i <= number; i++)
    {
        int n;
        scanf("%d", &n);
        balls[n] = i;
    }

    int count;
    scanf("%d", &count);

    for (int i = 0; i < count; i++)
    {
        int n;
        scanf("%d", &n);

        if (balls.count(n) == 0)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", balls.at(n));
        }
    }

    return 0;
}