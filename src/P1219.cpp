#include <cstdio>
#include <cmath>

using namespace std;

class BFS
{
private:
    int *array;
    int pos = 0;
    int diamond;
    // 对角线占用数组
    bool *k1, *k2, *used;

public:
    int result = 0;

    BFS(int diamond)
    {
        this->diamond = diamond;
        k1 = new bool[diamond * 2 + 1];
        k2 = new bool[diamond * 2 + 1];
        used = new bool[diamond + 1];
        array = new int[diamond];

        for (int i = 0; i <= diamond * 2; i++)
        {
            k1[i] = false;
            k2[i] = false;
        }

        for (int i = 1; i <= diamond; i++)
        {
            used[i] = false;
        }
    }

    ~BFS()
    {
        delete k1;
        delete k2;
        delete used;
        delete array;
    }

    void dfs(int now, int count)
    {
        // 这里的size需要加1
        // 因为后面添加的时候都是在push_back之后
        if (k1[pos + 1 + now] or k2[pos + 1 - now + diamond] or used[now])
        {
            return;
        }
        
        array[pos] = now;
        pos++;
        used[now] = true;
        k1[pos + now] = true;
        k2[pos - now + diamond] = true;

        if (count == diamond)
        {
            if (result < 3)
            {
                for (int i = 0; i < pos; i++)
                {
                    printf("%d ", array[i]);
                }
                printf("\n");
            }
            result++;

            used[now] = false;
            k1[pos + now] = false;
            k2[pos - now + diamond] = false;
            pos--;
            return;
        }

        for (int i = 1; i <= diamond; i++)
        {
            dfs(i, count + 1);
        }

        used[now] = false;
        k1[pos + now] = false;
        k2[pos - now + diamond] = false;
        pos--;
    }
};

int main()
{
    int d;
    scanf("%d", &d);

    BFS dfs(d);

    for (int i = 1; i <= d; i++)
    {
        dfs.dfs(i, 1);
    }

    printf("%d\n", dfs.result);
    return 0;
}