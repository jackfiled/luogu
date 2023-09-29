#include <cstdio>
#include <set>

int main()
{
    std::multiset<int> tree;

    int number;
    scanf("%d", &number);

    for (int i = 0; i < number; i++)
    {
        int operation, value;
        scanf("%d %d", &operation, &value);

        switch (operation)
        {
        case 1:
        {
            auto pos = tree.lower_bound(value);

            printf("%ld\n", std::distance(tree.begin(), pos) + 1);
            break;
        }
        case 2:
        {
            auto pos = tree.begin();

            for (int i = 0; i < value - 1; i++)
            {
                pos++;
            }

            printf("%d\n", *pos);
            break;
        }
        case 3:
        {
            auto pos = tree.lower_bound(value);

            if (pos == tree.begin())
            {
                printf("%d\n", -2147483647);
            }
            else
            {
                pos--;
                printf("%d\n", *pos);
            }
            break;
        }
        case 4:
        {
            auto pos = tree.upper_bound(value);

            if (pos == tree.end())
            {
                printf("%d\n", 2147483647);
            }
            else
            {
                printf("%d\n", *pos);
            }
            break;
        }
        case 5:
        {
            tree.emplace(value);
            break;
        }
        }
    }

    return 0;
}