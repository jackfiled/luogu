#include <cstdio>
#include <list>
#include <unordered_map>

using namespace std;

int main()
{
    int number;
    scanf("%d", &number);
    
    unordered_map<int, list<int>::iterator> posMap;
    list<int> queue;

    queue.push_back(1);
    posMap[1] = queue.begin();

    for (int n = 2; n <= number; n++)
    {
        int target, direction;
        scanf("%d %d", &target, &direction);

        auto i = posMap[target];

        if (direction == 1)
        {
            i++;
        }
        posMap[n] = queue.insert(i, n);
    }

    scanf("%d", &number);

    for (int i = 0; i < number; i++)
    {
        int remove;
        scanf("%d", &remove);

        auto pos = posMap.find(remove);

        if (pos != posMap.end())
        {
            queue.erase(pos->second);
            posMap.erase(remove);
        }
    }

    for (auto i : queue)
    {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}