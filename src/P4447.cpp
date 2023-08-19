#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Group
{
    int target;
    int size;
};

bool compare(const Group &a, const Group &b)
{
    return a.target < b.target;
}

int main()
{
    int number;
    scanf("%d", &number);

    int forces[number];
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &forces[i]);
    }

    sort(forces, forces + number);

    vector<Group> groups;

    for (const int &i : forces)
    {
        Group target = {
            .target = i,
        };
        auto pos = lower_bound(groups.begin(), groups.end(), target, compare);

        while (pos != groups.end() and pos->target == (pos + 1)->target)
        {
            pos++;
        }

        if (pos == groups.end() or pos->target != i)
        {
            // 到达末尾或者没有找到
            // 添加新一组
            target = {
                .target = i + 1,
                .size = 1,
            };
            groups.push_back(target);
        }
        else
        {
            // 加入该组
            pos->target++;
            pos->size++;
        }
    }

    int min = 0x7fffffff;
    for (auto i : groups)
    {
        min = i.size < min ? i.size : min;
    }
    printf("%d\n", min);

    return 0;
}