#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    int people, number;
    scanf("%d %d", &people, &number);

    int tickets[number];
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &tickets[i]);
    }

    sort(tickets, tickets + number);

    for (int i = 0; i < number; i++)
    {
        if (i == number - 1)
        {
            printf("%d\n", tickets[i]);
        }
        else
        {
            printf("%d ", tickets[i]);
        }
    }

    return 0;
}