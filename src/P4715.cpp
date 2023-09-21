#include <cstdio>
#include <cmath>

struct Nation
{
    int strength;
    int id;
};

int main()
{
    int number;
    scanf("%d", &number);
    int length = (int)pow(2, number);

    Nation nations[length];

    for (int i = 0; i < length; i++)
    {
        nations[i].id = i + 1;
        scanf("%d", &nations[i].strength);
    }

    for (int i = number; i > 1; i--)
    {
        int bond = (int)pow(2, i);

        for (int j = 0; j < bond / 2; j++)
        {
            if (nations[2 * j].strength < nations[2 * j + 1].strength)
            {
                nations[j].strength = nations[2 * j + 1].strength;
                nations[j].id = nations[2 * j + 1].id; 
            }
            else
            {
                nations[j].strength = nations[2 * j].strength;
                nations[j].id = nations[2 * j].id;
            }
        }
    }

    if (nations[0].strength > nations[1].strength)
    {
        printf("%d\n", nations[1].id);
    }
    else
    {
        printf("%d\n", nations[0].id);
    }

    return 0;
}