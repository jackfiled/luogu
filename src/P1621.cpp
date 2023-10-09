#include <cstdio>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <memory>

using namespace std;

// 引用https://www.luogu.com.cn/blog/nopartyfoucaodong/solution-p3383
bool isPrime(int x)
{
    if (x == 1)
    {
        return false;
    }

    if (x == 2 || x == 3)
    {
        return true;
    }

    if (x % 6 != 1 && x % 6 != 5)
    {
        return false;
    }

    for (int i = 5; i <= sqrt(x); i = i + 6)
    {
        if (x % i == 0 || x % (i + 2) == 0)
        {
            return false;
        }
    }

    return true;
}

struct UnionFind
{
    unique_ptr<int[]> fathers;

    UnionFind(int number)
    {
        fathers = unique_ptr<int[]>(new int[number + 1]);

        for (int i = 1; i <= number; i++)
        {
            fathers[i] = i;
        }
    }

    int find(int x)
    {
        if (fathers[x] == x)
        {
            return x;
        }

        fathers[x] = find(fathers[x]);
        return fathers[x];
    }

    void merge(int a, int b)
    {
        a = find(a);
        b = find(b);

        fathers[a] = b;
    }
};

int main()
{
    int a, b, p;
    scanf("%d %d %d", &a, &b, &p);

    vector<int> primes;

    for (int i = 1; i <= b; i++)
    {
        if (isPrime(i))
        {
            primes.emplace_back(i);
        }
    }

    UnionFind unionFind(b);

    for (const int& i : primes)
    {
        if (i < p)
        {
            continue;
        }

        int start = ceil(a * 1.0 / i);

        while (start * i <= b)
        {
            unionFind.merge(i, start * i);
            start++;
        }
    }

    unordered_set<int> s;
    for (int i = a; i <= b; i++)
    {
        s.emplace(unionFind.find(i));
    }

    printf("%ld\n", s.size());
    return 0;
}