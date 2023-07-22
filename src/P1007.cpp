#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int length, number;
    scanf("%d", &length);
    scanf("%d", &number);

    int maxTime = 0, minTime = 0;
    for (int i = 0; i < number; i++)
    {
        int pos;
        scanf("%d", &pos);
        // 最短的时间就是士兵都往近的一端走的最长时间
        minTime = max(min(length + 1 - pos, pos), minTime);
        // 最长的时间就是士兵都往远的一端走的最长时间
        maxTime = max(max(length + 1 - pos, pos), maxTime);
    }

    printf("%d %d\n", minTime, maxTime);
    return 0;
}