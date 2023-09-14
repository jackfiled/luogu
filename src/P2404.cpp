#include <cstdio>

class DFS
{
public:
    int number;

    void dfs(int sum, int next)
    {
        if (sum == number)
        {
            print();
            return;
        }

        for (int i = next; i <= number - sum; i++)
        {
            array[pos] = i;
            pos++;
            dfs(sum + i, i);
            pos--;
        }
    }

private:
    int array[10];
    int pos = 0;

    void print()
    {
        if (pos == 1)
        {
            return;
        }

        printf("%d", array[0]);

        for (int i = 1; i < pos; i++)
        {
            printf("+%d", array[i]);
        }

        printf("\n");
    }
};

int main()
{
    DFS dfs;

    scanf("%d", &dfs.number);

    dfs.dfs(0, 1);

    return 0;
}