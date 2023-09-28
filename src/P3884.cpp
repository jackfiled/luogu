#include <cstdio>
#include <unordered_map>
#include <climits>
#define max(a, b) ((a) < (b) ? (b) : (a))
#define min(a, b) ((a) < (b) ? (a) : (b))

int main()
{
    int number;
    scanf("%d", &number);

    int tree[number + 1][number + 1];

    for (int i = 1; i <= number; i++)
    {
        for (int j = 1; j <= number; j++)
        {
            if (i != j)
            {
                tree[i][j] = INT_MAX / 4;
            }
            else
            {
                tree[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < number; i++)
    {
        int left, right;
        scanf("%d %d", &left, &right);

        tree[left][right] = 1;
        tree[right][left] = 2;
    }

    for (int k = 1; k <= number; k++)
    {
        for (int i = 1; i <= number; i++)
        {
            for (int j = 1; j <= number; j++)
            {
                tree[i][j] = min(tree[i][j], tree[i][k] + tree[k][j]);
            }
        }
    }

    int height = 0;
    std::unordered_map<int, int> widthMap;
    for (int i = 2; i <= number; i++)
    {
        height = max(height, tree[1][i]);

        widthMap[tree[1][i]]++;
    }

    int width = 0;

    for (const auto &pair : widthMap)
    {
        width = max(width, pair.second);
    }

    int u, v;
    scanf("%d %d", &u, &v);

    printf("%d\n", height + 1);
    printf("%d\n", width);
    printf("%d\n", tree[u][v]);
    return 0;
}