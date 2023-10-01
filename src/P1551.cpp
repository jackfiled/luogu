#include <cstdio>

struct UnionFind
{
    int *father;

    UnionFind(int number)
    {
        father = new int[number + 1];

        for (int i = 1; i <= number; i++)
        {
            father[i] = i;
        }
    }

    ~UnionFind()
    {
        delete father;
    }

    int find(int x)
    {
        if (x == father[x])
        {
            return x;
        }
        else
        {
            return find(father[x]);
        }
    }

    void merge(int i, int j)
    {
        father[find(i)] = find(j);
    }
};

int main()
{
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);

    UnionFind u(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        u.merge(a, b);
    }

    for (int i = 0; i < p; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        if (u.find(a) == u.find(b))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}