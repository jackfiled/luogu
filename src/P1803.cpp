#include <cstdio>
#include <algorithm>

using namespace std;

struct Competition
{
    int begin, end;  
};

bool compare(const Competition& a, const Competition& b)
{
    return a.end < b.end;
}

int main()
{
    int number;
    scanf("%d", &number);

    Competition competitions[number];

    for (int i = 0; i < number; i++)
    {
        scanf("%d %d", &competitions[i].begin, &competitions[i].end);
    }

    sort(competitions, competitions + number, compare);

    int now = 0, result = 0;
    for (Competition& i : competitions)
    {
        if (now <= i.begin)
        {
            now = i.end;
            result++;
        }
    }

    printf("%d\n", result);
    return 0;
}