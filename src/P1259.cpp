#include <cstdio>
#include <string>

using namespace std;

string base[] = {"ooo--***o*", "ooo*o**--*", "o--*o**oo*", "o*o*o*--o*", "--o*o*o*o*"};

string moveStr(const string& input)
{
    // 找到第一个 o*
    int oPos, starPos, length = input.length();
    for (int i = 0; i < length - 1; i++)
    {
        if (input[i] == 'o' and input[i + 1] == '*')
        {
            oPos = i;
            starPos = i + 1;
            break;
        }
    }

    // 找到空位
    int space1, space2;
    for (int i = 0; i < length - 1; i++)
    {
        if (input[i] == '-' and input[i + 1] == '-')
        {
            space1 = i;
            space2 = i + 1;
            break;
        }
    }


    string result(input);
    result[space1] = 'o';
    result[space2] = '*';
    result[oPos] = '-';
    result[starPos] = '-';

    printf("%s\n", result.c_str());

    // 移动空位
    result[oPos] = '*';
    result[starPos] = '*';
    result[space1 - 1] = '-';
    result[space1 - 2] = '-';

    printf("%s\n", result.c_str());

    return result;
}

int main()
{
    int number, time;
    scanf("%d", &number);
    time = number;
    string input;
    for (int i = 0; i < number; i++)
    {
        input.push_back('o');
    }
    for (int i = 0; i < number; i++)
    {
        input.push_back('*');
    }
    input.push_back('-');
    input.push_back('-');

    printf("%s\n", input.c_str());

    while(time > 4)
    {
        input = moveStr(input);
        time--;
    }

    for (string& s : base)
    {
        printf("%s", s.c_str());

        for (int i = 0; i < number - 4; i++)
        {
            printf("o*");
        }
        printf("\n");
    }

    return 0;
}