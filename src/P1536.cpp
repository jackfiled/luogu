#include <cstdio>
#include <memory>
#include <unordered_set>

using namespace std;

struct UnionFind
{
    unique_ptr<int[]> Parents;

    UnionFind(int number)
    {
        Parents = unique_ptr<int[]>(new int[number + 1]);

        for (int i = 1; i <= number; i++)
        {
            Parents[i] = i;
        }
    }

    int find(const int& x)
    {
        if (x == Parents[x])
        {
            return x;
        }
        else
        {
            // 路径压缩
            Parents[x] = find(Parents[x]);
            return Parents[x];
        }
    }

    void merge(const int& i, const int& j)
    {
        Parents[find(i)] = find(j);
    }
};

int main()
{
    int city;

    scanf("%d", &city);

    while (city != 0)
    {
        int road;
        scanf("%d", &road);

        UnionFind roads(city);

        for (int i = 0; i < road; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);

            roads.merge(a, b);
        }

        unordered_set<int> s;

        for (int i = 1; i <= city; i++)
        {
            s.emplace(roads.find(i));
        }

        printf("%ld\n", s.size() - 1);

        scanf("%d", &city);
    }

    return 0;
}