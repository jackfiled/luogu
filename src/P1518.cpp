#include <cstdio>
#include <cstring>

int map[12][12];
char states[164110];

class Farmer 
{
public:
    int x, y, face;

    Farmer(int x, int y)
    {
        this->x = x;
        this->y = y;
        this->face = 0;
    }

    void forward() 
    {
        switch(face)
        {
            case 0:
            {
                // 向上走
                if (map[x - 1][y] == '*')
                {
                    // 拐弯
                    face = 1;
                }
                else
                {
                    x--;
                }
                break;
            }
            case 1:
            {
                // 向右走
                if (map[x][y + 1] == '*')
                {
                    // 拐弯
                    face = 2;
                }
                else
                {
                    y++;
                }
                break;
            }
            case 2:
            {
                // 向下走
                if (map[x + 1][y] == '*')
                {
                    // 拐弯
                    face = 3;
                }
                else
                {
                    x++;
                }
                break;
            }
            case 3:
            {
                // 向左走
                if (map[x][y - 1] == '*')
                {
                    // 拐弯
                    face = 0;
                }
                else
                {
                    y--;
                }
                break;
            }
        }
    }
};

int main()
{
    Farmer *farmer, *cow;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            map[i][j] = '*';
        }
    }

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            map[i][j] = ' ';
            char c = getchar();
            if (c == '*')
            {
                map[i][j] = '*';
            }
            else if (c == 'F')
            {
                farmer = new Farmer(i, j);
            }
            else if (c == 'C')
            {
                cow = new Farmer(i, j);
            }
        }
        // 读取行末尾的换行符
        getchar();
    }

    int time = 0;
    memset(states, 0, sizeof(char) * 164110);
    while(true)
    {
        if (farmer->x == cow->x and farmer->y == cow->y)
        {
            break;
        }

        farmer->forward();
        cow->forward();
        time++;

        int feature = farmer->x + farmer->y * 10 + cow->x * 100 + cow->y * 1000 
            + farmer->face * 10000 + cow->face * 40000;

        if (states[feature] == 1)
        {
            // 已经到达过这个状态
            time = 0;
            break;
        }
        else
        {
            states[feature] = 1;
        }
    }

    printf("%d\n", time);

    delete farmer;
    delete cow;
    return 0;
}