#include <cstdio>
#include <cstring>
#include <list>

using namespace std;

int main()
{
    char numberStr[300];
    scanf("%s", numberStr);
    int k;
    scanf("%d", &k);
    
    int length = strlen(numberStr);
    list<int> number;

    for (int i = 0; i < length; i++)
    {
        number.push_back(numberStr[i] - '0');
    }

    for (int i = 0; i < k; i++)
    {
        auto first = number.begin();
        auto second = number.begin();
        second++;

        while(true)
        {
            if (second == number.end() and *first > 0)
            {
                number.erase(first);
                break;
            }

            if (*first > *second)
            {
                first = number.erase(first);
                break;
            }
            else
            {
                first++;
            }

            second++;
        }
    }

    bool allZero = true;
    for (auto i = number.begin(); i != number.end(); i++)
    {
        if (*i == 0 and allZero)
        {
            continue;
        }
        else if (*i != 0)
        {
            allZero = false;
        }

        printf("%d", *i);
    }

    if (allZero)
    {
        printf("0\n");
    }
    else
    {
        printf("\n");
    }

    return 0;
}