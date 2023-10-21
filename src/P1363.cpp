#include <iostream>
#include <vector>

using namespace std;

struct Maza
{
    vector<vector<bool>> matrix;
    vector<vector<vector<int>>> visited;
    bool flag = false;
    int height, width;

    const int dx[4] = {1, -1, 0 , 0};
    const int dy[4] = {0, 0 , -1, 1};

    Maza(int n, int m)
    {
        matrix = vector<vector<bool>>(n, vector<bool>(m, false));
        visited = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(3, 0)));

        height = n;
        width = m;
    }

    void dfs(int x, int y, int lx, int ly)
    {
        if (flag)
        {
            return;
        }

        if (visited[x][y][0] != 0 and (visited[x][y][1] != lx or visited[x][y][2] != ly))
        {
            flag = true;
            return;
        }

        visited[x][y][0] = 1;
        visited[x][y][1] = lx;
        visited[x][y][2] = ly;

        for (int i = 0; i < 4; i++)
        {
            // 加上一个数再取模避免出现负数
            int xx = (x + dx[i] + height) % height;
            int yy = (y + dy[i] + width) % width;

            int lxx = lx + dx[i];
            int lyy = ly + dy[i];

            if (matrix[xx][yy])
            {
                if (visited[xx][yy][1] != lxx or visited[xx][yy][2] != lyy or visited[xx][yy][0] == 0)
                {
                    dfs(xx, yy, lxx, lyy);
                }
            }
        }

    }    
};

int main()
{
    ios::sync_with_stdio(false);

    int n, m;
    while (cin >> n >> m)
    {
        Maza maza(n, m);

        int startX, startY;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char c;
                cin >> c;
                if (c == '#')
                {
                    maza.matrix[i][j] = false;
                }
                else if (c == '.')
                {
                    maza.matrix[i][j] = true;
                }
                else if (c == 'S')
                {
                    maza.matrix[i][j] = true;
                    startX = i;
                    startY = j;
                }
            }
        }

        maza.dfs(startX, startY, startX, startY);

        if (maza.flag)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}