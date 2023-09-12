#include <cstdio>
#include <map>

using namespace std;

int main()
{
    int number, time;
    scanf("%d %d", &number, &time);

    map<int, int> maps[number + 1];

    for (int count = 0; count < time; count++)
    {
        int o;
        scanf("%d", &o);

        if (o == 1)
        {
            int i, j, k;
            scanf("%d %d %d", &i, &j, &k);

            if (k == 0)
            {
                maps[i].erase(j);
            }
            else
            {
                maps[i][j] = k;
            }
        }
        else
        {
            int i, j;
            scanf("%d %d", &i, &j);

            printf("%d\n", maps[i][j]);
        }
    }

    return 0;
}