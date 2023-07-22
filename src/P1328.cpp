#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int number, a, b;
    scanf("%d %d %d", &number, &a, &b);

    vector<int> aArray, bArray;

    // 输入A的出拳规律
    for (int i = 0; i < a; i++)
    {
        int input;
        scanf("%d", &input);
        aArray.push_back(input);
    }

    // 输入B的出拳规律
    for (int i = 0; i < b; i++)
    {
        int input;
        scanf("%d", &input);
        bArray.push_back(input);
    }

    auto aItor = aArray.begin();
    auto bItor = bArray.begin();
    int aResult = 0, bResult = 0;

    for (int i = 0; i < number; i++)
    {
        if (aItor == aArray.end())
        {
            aItor = aArray.begin();
        }

        if (bItor == bArray.end())
        {
            bItor = bArray.begin();
        }

        if (*aItor == *bItor)
        {
            // 平局
            aItor++;
            bItor++;
            continue;
        }

        switch (*aItor)
        {
        case (0):
        {
            // 我方出剪刀
            if (*bItor == 2 or *bItor == 3)
            {
                // 对方出布和蜥蜴人
                aResult++;
            }
            else
            {
                bResult++;
            }
            break;
        }
        case (1):
        {
            // 我方出石头
            if (*bItor == 0 or *bItor == 3)
            {
                // 对方出剪刀和蜥蜴人
                aResult++;
            }
            else
            {
                bResult++;
            }
            break;
        }
        case (2):
        {
            // 我方出布
            if (*bItor == 1 or *bItor == 4)
            {
                // 对方出石头和蜥蜴人
                aResult++;
            }
            else
            {
                bResult++;
            }
            break;
        }
        case (3):
        {
            // 我方出蜥蜴人
            if (*bItor == 2 or *bItor == 4)
            {
                // 对方出布和斯波克
                aResult++;
            }
            else
            {
                bResult++;
            }
            break;
        }
        case (4):
        {
            // 我方出斯波克
            if (*bItor == 0 or *bItor == 1)
            {
                // 对方出剪刀和石头
                aResult++;
            }
            else
            {
                bResult++;
            }
            break;
        }
        }

        aItor++;
        bItor++;
    }

    printf("%d %d\n", aResult, bResult);
    return 0;
}