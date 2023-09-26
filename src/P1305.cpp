#include <iostream>

using namespace std;

struct Node
{
    int left = 0;
    int right = 0;
};

void preorder(const Node tree[], int node)
{
    cout << (char)node;

    const Node &n = tree[node];

    if (n.left != 0)
    {
        preorder(tree, n.left);
    }

    if (n.right != 0)
    {
        preorder(tree, n.right);
    }
}

int main()
{
    Node tree[150];
    int number;
    cin >> number;

    int root;

    for (int i = 0; i < number; i++)
    {
        char r, left, right;
        cin >> r >> left >> right;

        if (i == 0)
        {
            root = r;
        }

        Node &rootNode = tree[(int)r];
        if (left != '*')
        {
            rootNode.left = left;
        }
        
        if (right != '*')
        {
            rootNode.right = right;
        }
    }

    preorder(tree, root);
    cout << endl;
    return 0;
}