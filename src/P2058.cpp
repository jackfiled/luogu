#include <cstdio>
#include <queue>
#include <unordered_map>
using namespace std;

struct People
{
    int second;
    int nation;
};

int main()
{
    int number;
    scanf("%d", &number);

    unordered_map<int, int> nations;
    queue<People> peoples;

    for (int i = 0; i < number; i++)
    {
        int second, people;
        scanf("%d %d", &second, &people);

        while (!peoples.empty())
        {
            auto front = peoples.front();

            if (front.second <= second - 86400)
            {
                nations[front.nation]--;
                if (nations[front.nation] == 0)
                {
                    nations.erase(front.nation);
                }
                peoples.pop();
            }
            else
            {
                break;
            }
        }

        for (int j = 0; j < people; j++)
        {
            int nation;
            scanf("%d", &nation);

            People p = {
                .second = second,
                .nation = nation};

            peoples.push(p);
            nations[nation]++;
        }

        printf("%d\n", (int)nations.size());
    }

    return 0;
}
