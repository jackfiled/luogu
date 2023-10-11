#include <cstdio>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct UnionFind
{
    unordered_map<int, int> map;

    int find(int x)
    {
        if (map.count(x) == 0 || map.at(x) == x)
        {
            map.emplace(x, x);
            return x;
        }

        map[x] = find(map[x]);
        return map[x];
    }

    void merge(int a, int b)
    {
        a = find(a);
        b = find(b);

        map[a] = b;
    }
};

struct Pattern
{
    int a, b, o;
};

bool compare(const Pattern& a, const Pattern& b)
{
    return a.o > b.o;
}
int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int count;
        scanf("%d", &count);

        Pattern patterns[count];

        for (int j = 0; j < count; j++)
        {
            scanf("%d %d %d", &patterns[j].a, &patterns[j].b, &patterns[j].o);
        }

        sort(patterns, patterns + count, compare);

        UnionFind unionFind;
        bool flag = true;
        for (int j = 0; j < count; j++)
        {
            if (patterns[j].o == 1)
            {
                unionFind.merge(patterns[j].a, patterns[j].b);
            }
            else
            {
                if (unionFind.find(patterns[j].a) == unionFind.find(patterns[j].b))
                {
                    flag = false;
                    break;
                }
            }
        }

        if (flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}