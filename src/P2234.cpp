#include <cstdio>
#include <set>
#include <cmath>

using namespace std;

int main()
{
    int number;
    scanf("%d", &number);
    set<int> tree;

    int result = 0;
    for (int i = 0; i < number; i++)
    {
        int input;
        scanf("%d", &input);

        auto pair = tree.insert(input);

        if (!pair.second)
        {
            continue;
        }

        if (tree.size() == 1)
        {
            result = result + input;
        }
        else
        {
            auto pos = pair.first;

            if (pos == tree.begin())
            {
                // 取下一个节点
                pos++;
                result = result + abs(*pos - input);
            }
            else
            {
                auto before = pos;
                before--;
                auto after = pos;
                after++;

                if (after == tree.end())
                {
                    result = result + abs(*before - input);
                }
                else
                {
                    int beforeLength = abs(*before - input);
                    int afterLength = abs(*after - input);

                    result = result + min(beforeLength, afterLength);
                }
            }
        }
    }

    printf("%d\n", result);
    return 0;
}