#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int length, number;
    scanf("%d %d", &length, &number);

    // 考虑终点上的树
    vector<int> tree(length + 1);

    for (int i = 0; i < number; i++)
    {
        int begin, end;
        scanf("%d %d", &begin, &end);

        for (int j = begin; j <= end; j++)
        {
            tree[j] = -1;
        }
    }

    int result = 0;
    for (auto i = tree.begin(); i < tree.end(); i++)
    {
        if (*i == 0)
        {
            result++;
        }
    }

    printf("%d\n", result);
    return 0;
}