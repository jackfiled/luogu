// 我他妈直接跪下 https://www.luogu.com.cn/blog/222223/solution-p1990

#include <cstdio>
#include <cstring>

int main()
{
    int f1[5] = {0}, f2[5] = {0}, f3[5] = {0};
    f1[1] = 1;
    f2[1] = 2;
    f3[1] = 5;

    int number;
    scanf("%d", &number);

    for (int i = 4; i <= number; i++)
    {
        int temp[5];
        // temp = f2
        memcpy(temp, f2, sizeof(temp));
        // f2 = f3
        memcpy(f2, f3, sizeof(f3));

        // f3 = f3 * 2 + f1;
        int overflow = 0;
        int temp2[5] = {0};
        for (int i = 1; i <= 4; i++)
        {
            int sum = f3[i] * 2 + f1[i] + overflow;
            temp2[i] = sum % 10;
            overflow = sum / 10;
        }
        memcpy(f3, temp2, sizeof(temp2));

        // f1 = temp;
        memcpy(f1, temp, sizeof(temp));
    }

    switch (number)
    {
    case 1:
        printf("1\n");
        break;
    case 2:
        printf("2\n");
        break;
    case 3:
        printf("5\n");
        break;
    default:
        bool flag = true;
        for (int i = 4; i >= 1; i--)
        {
            if (f3[i] == 0 and flag)
            {
                continue;
            }
            
            if (f3[i] != 0)
            {
                flag = false;
            }
            printf("%d", f3[i]);
        }
        printf("\n");
    }
    return 0;
}