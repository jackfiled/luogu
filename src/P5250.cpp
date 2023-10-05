#include <cstdio>
#include <set>

using namespace std;

int main()
{
    int number;
    scanf("%d", &number);

    set<int> warehourse;

    for(int i = 0; i < number; i++)
    {
        int control, length;
        scanf("%d %d", &control, &length);

        if (control == 1)
        {
            // add
            if (warehourse.count(length) == 1)
            {
                printf("Already Exist\n");
            }
            else
            {
                warehourse.emplace(length);
            }
        }
        else
        {
            if (warehourse.size() == 0)
            {
                printf("Empty\n");
                continue;
            }

            if (warehourse.count(length) == 1)
            {
                printf("%d\n", length);
                warehourse.erase(length);
                continue;
            }

            auto right = warehourse.upper_bound(length);
            if (right == warehourse.end())
            {
                printf("%d\n", *warehourse.rbegin());
                warehourse.erase(*warehourse.rbegin());
            }
            else if (right == warehourse.begin())
            {
                printf("%d\n", *right);
                warehourse.erase(right);
            }
            else
            {
                auto left = right;
                left--;

                if (*right - length >= length - *left)
                {
                    printf("%d\n", *left);
                    warehourse.erase(left);
                }
                else
                {
                    printf("%d\n", *right);
                    warehourse.erase(right);
                }
            }
        }
    }

    return 0;
}