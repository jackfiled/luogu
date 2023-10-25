#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int r;
    scanf("%d", &r);

    vector<vector<int>> tree = vector<vector<int>>(r);

    for (int i = 1; i <= r; i++)
    {
        tree[i - 1] = vector<int>(i);

        for (int j = 0; j < i; j++)
        {
            int n;
            scanf("%d", &n);
            tree[i - 1][j] = n;
        }
    }

    for (int i = r - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            tree[i][j] = tree[i][j] + max(tree[i + 1][j], tree[i + 1][j + 1]);
        }
    }

    printf("%d\n", tree[0][0]);
    return 0;
}