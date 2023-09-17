#include <cstdio>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, vector<int>> dependency;

void add(unordered_set<int> &set, int d)
{
    if (set.count(d) == 1)
    {
        return;
    }

    set.emplace(d);

    auto array = dependency[d];

    if (!array.empty())
    {
        for (auto i : array)
        {
            add(set, i);
        }
    }
}

int main()
{
    int number;
    scanf("%d", &number);

    for (int i = 1; i <= number; i++)
    {
        int n;
        scanf("%d", &n);
        vector<int> array;

        for (int j = 0; j < n; j++)
        {
            int temp;
            scanf("%d", &temp);

            array.push_back(temp);
        }

        dependency[i] = array;
    }

    unordered_set<int> set;

    add(set, 1);

    printf("%d\n", (int)set.size());
    return 0;
}