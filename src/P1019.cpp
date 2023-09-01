#include <iostream>
#include <string>

using namespace std;

class DFS
{
public:
    int number;
    string words[30];
    int visit[30];
    int result = -1;

    void init()
    {
        for (int i = 0; i < number; i++)
        {
            for (int j = 0; j < number; j++)
            {
                generate_relation(i, j);
            }
        }

        for (int i = 0; i < number; i++)
        {
            visit[i] = 0;
        }
    }

    void dfs(int pos, int length)
    {
        bool flag = false;

        for (int i = 0; i < number; i++)
        {
            // 已经被使用多次
            if (visit[i] >= 2)
            {
                continue;
            }

            // 没有重叠的部分
            if (relation[pos][i] == 0)
            {
                continue;
            }

            // 相互包含
            if (relation[pos][i] == (int)words[pos].size()
                or relation[pos][i] == (int)words[i].size())
            {
                continue;
            }

            visit[i]++;
            flag = true;
            dfs(i, length + (int)words[i].size() - relation[pos][i]);
            visit[i]--;
        }

        if (!flag)
        {
            result = max(result, length);
        }
    }



private:
    int relation[30][30];

    void generate_relation(int x, int y)
    {
        string &front = words[x];
        string &back = words[y];
        relation[x][y] = 0;

        for (int pos = (int)front.size() - 1; pos >= 0; pos--)
        {
            bool flag = true;
            int j = 0;
            for (int i = pos; i < (int)front.size() and j < (int)back.size(); i++, j++)
            {
                if (front[i] != back[j])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                relation[x][y] = j;
                break;
            }

            // 到达back的末尾
            if (j == (int)back.size())
            {
                break;
            }
        }
    }
};

int main()
{
    DFS dfs;
    cin >> dfs.number;
    for (int i = 0; i < dfs.number; i++)
    {
        cin >> dfs.words[i];
    }
    dfs.init();

    char start;
    cin >> start;

    for (int i = 0; i < dfs.number; i++)
    {
        if (dfs.words[i][0] == start)
        {
            dfs.visit[i]++;
            dfs.dfs(i, (int)dfs.words[i].size());
            dfs.visit[i]--;
        }
    }

    printf("%d\n", dfs.result);
    return 0;
}