#include <cstdio>
#include <algorithm>
#include <memory>

using namespace std;

struct Crime
{
    int a, b;
    int score;
};

inline bool compare(const Crime& a, const Crime& b)
{
    return a.score > b.score;
}

struct UnionFind
{
    unique_ptr<int[]> parents;

    UnionFind(int number)
    {
        parents = unique_ptr<int[]>(new int[number + 1]);

        for (int i = 1; i <= number; i++)
        {
            parents[i] = i;
        }
    }

    int find(int x)
    {
        if (parents[x] == x)
        {
            return x;
        }

        parents[x] = find(parents[x]);
        return parents[x];
    }

    void merge(int a, int b)
    {
        a = find(a);
        b = find(b);

        parents[a] = b;
    }
};

int main()
{
    int number, count;
    scanf("%d %d", &number, &count);

    UnionFind prison(number);

    Crime crimes[count];

    for (int i = 0; i < count; i++)
    {
        scanf("%d %d %d", &crimes[i].a, &crimes[i].b, &crimes[i].score);
    }

    sort(crimes, crimes + count, compare);

    bool flag = false;
    int enemy[number + 1];
    for (int i = 1; i <= number; i++)
    {
        enemy[i] = 0;
    }
    for (const auto& c : crimes)
    {
        if (prison.find(c.a) == prison.find(c.b))
        {
            printf("%d\n", c.score);
            flag = true;
            break;
        }

        if (enemy[c.a] == 0)
        {
            enemy[c.a] = c.b;
        }
        else
        {
            prison.merge(enemy[c.a], c.b);
        }

        if (enemy[c.b] == 0)
        {
            enemy[c.b] = c.a;
        }
        else
        {
            prison.merge(enemy[c.b], c.a);
        }
    }

    if (!flag)
    {
        printf("0\n");
    }

    return 0;
}
