#include <cstdio>

struct Node
{
    int people;
    int left;
    int right;
};

int depth(const Node trees[], const Node &node)
{
    int d = 0;
    if (node.left != 0)
    {
        const Node &left = trees[node.left];
        d = d + depth(trees, left) + left.people;
    }

    if (node.right != 0)
    {
        const Node &right = trees[node.right];
        d = d + depth(trees, right) + right.people;
    }

    return d;
}

int dfs(const Node trees[], const Node &next, int level)
{
    int distance = 0;
    if (next.left != 0)
    {
        const Node& left = trees[next.left];
        distance = distance + left.people * level + dfs(trees, left, level + 1);
    }

    if (next.right != 0)
    {
        const Node& right = trees[next.right];
        distance = distance + right.people * level + dfs(trees, right, level + 1);
    }

    return distance;
}

void dp(const Node trees[], const int size[], int distance[], int u)
{
    const Node& node = trees[u];

    if (node.left != 0)
    {
        distance[node.left] = distance[u] + size[1] - 2 * size[node.left];
        dp(trees, size, distance, node.left);
    }

    if (node.right != 0)
    {
        distance[node.right] = distance[u] + size[1] - 2 * size[node.right];
        dp(trees, size, distance, node.right);
    }
}

int main()
{
    int number;
    scanf("%d", &number);

    Node trees[number + 1];

    for (int i = 1; i <= number; i++)
    {
        scanf("%d %d %d", &trees[i].people, &trees[i].left, &trees[i].right);
    }

    int size[number + 1];
    for (int i = 1; i <= number; i++)
    {
        size[i] = depth(trees, trees[i]) + trees[i].people;
    }

    int distance[number + 1];
    distance[1] = dfs(trees, trees[1], 1);
    dp(trees, size, distance, 1);

    int min = 0x7fffffff;    
    for (int i = 1; i <= number; i++)
    {
        if (distance[i] < min)
        {
            min = distance[i];
        }
    }

    printf("%d\n", min);
    return 0;
}