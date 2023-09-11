#include <cstdio>
#include <array>

using namespace std;

int main()
{
    int number, time;
    scanf("%d %d", &number, &time);
    const size_t length = 2e6;
    array<int, length> a;

    for (int i = 0; i < number; i++)
    {
        int temp;
        scanf("%d", &temp);
        a[i] = temp;
    }

    for (int i = 0; i < time; i++)
    {
        int pos;
        scanf("%d", &pos);
        printf("%d\n", a[pos - 1]);
    }

    return 0;
}