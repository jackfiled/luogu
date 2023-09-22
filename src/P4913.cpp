#include <cstdio>

struct Node
{
    Node *left = nullptr;
    Node *right = nullptr;
};

int height = 0;
void dfs(Node *node, int h)
{
    if (h > height)
    {
        height = h;
    }

    if (node->left != nullptr)
    {
        dfs(node->left, h + 1);
    }

    if (node->right != nullptr)
    {
        dfs(node->right, h + 1);
    }
}


int main()
{
    int number;
    scanf("%d", &number);

    Node trees[number + 1];

    for (int i = 1; i <= number; i++)
    {
        int left, right;
        scanf("%d %d", &left, &right);

        if (left != 0)
        {
            trees[i].left = &trees[left];
        }

        if (right != 0)
        {
            trees[i].right = &trees[right];
        }
    }

    dfs(&trees[1], 1);

    printf("%d\n", height);
    return 0;
}
