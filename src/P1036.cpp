#include <cstdio>
#include <cmath>

bool isPrime(int number)
{
    for (int i = 2; i < sqrt(number); i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}

class BFS {
public:
    int number;
    int target;
    int result = 0;
    int *array;

    void dfs(int now, int sum, int next)
    {
        if (now == target)
        {
            // 达到目标数量
            if (isPrime(sum))
            {
                result++;
            }

            return;
        }

        for (int i = next; i < number; i++)
        {
            dfs(now + 1, sum + array[i], i + 1);
        }
    }
};

int main()
{
    BFS dfs;
    scanf("%d %d", &dfs.number, &dfs.target);
    int array[dfs.number];
    dfs.array = array;

    for (int i = 0; i < dfs.number; i++)
    {
        scanf("%d", &array[i]);
    }

    dfs.dfs(0, 0, 0);
    printf("%d\n", dfs.result);
    return 0;
}