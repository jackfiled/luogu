#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    vector<bool> input;

    bool flag = true;
    while(flag)
    {
        char c = getchar();
        switch(c)
        {
            case 'W':
                input.push_back(true);
                break;
            case 'L':
                input.push_back(false);
                break;
            case 'E':
                flag = false;
                break;
            default:
                break;
        }
    }

    // 按照十一分制计算成绩
    int w = 0, l = 0;
    for (auto i = input.begin(); i != input.end(); i++)
    {
        if (*i)
        {
            w++;
        }
        else
        {
            l++;
        }

        if (abs(w - l) >= 2)
        {
            if (w >= 11 or l >= 11)
            {
                // 11分值 一局结束
                printf("%d:%d\n", w, l);
                w = 0;
                l = 0;
            }
        }
    }
    printf("%d:%d\n", w, l);
    w=l=0;
    
    printf("\n");
    for (auto i = input.begin(); i != input.end(); i++)
    {
        if (*i)
        {
            w++;
        }
        else
        {
            l++;
        }

        if (abs(w - l) >= 2)
        {
            if (w >= 21 or l >= 21)
            {
                // 21分值 一局结束
                printf("%d:%d\n", w, l);
                w = 0;
                l = 0;
            }
        }
    }
    printf("%d:%d\n", w, l);

    return 0;
}