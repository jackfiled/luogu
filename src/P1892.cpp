#include <iostream>
#include <memory>

using namespace std;

struct UnionFind
{
    unique_ptr<int[]> fathers;

    UnionFind(int number)
    {
        fathers = unique_ptr<int[]>(new int[2 * number + 1]);

        for (int i = 1; i <= 2 * number; i++)
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
    ios::sync_with_stdio(false);
    int number, count;
    cin >> number >> count;

    UnionFind unionFind(number);

    for (int i = 0 ; i < count; i++)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;

        if (c == 'F')
        {
            unionFind.merge(a, b);
        }
        else
        {
            unionFind.merge(a + number, b);
            unionFind.merge(b + number, a);
        }
    }

    int result = 0;
    for (int i = 1; i <= number; i++)
    {
        if (unionFind.fathers[i] == i)
        {
            result++;
        }
    }

    cout << result << endl;
    return 0;
}