#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int number, people;
    scanf("%d %d", &number, &people);

    int colleges[number];
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &colleges[i]);
    }

    sort(colleges, colleges + number);

    long long result = 0;
    for (int i = 0; i < people; i++)
    {
        int score;
        scanf("%d", &score);

        int pos = lower_bound(colleges, colleges + number, score) - colleges;

        if (pos == number)
        {
            result += abs(score - colleges[number - 1]);
        }
        else if (pos == 0)
        {
            result += abs(score - colleges[0]);
        }
        else
        {
            result += min(abs(score - colleges[pos]), abs(score - colleges[pos - 1]));
        }
    }

    printf("%lld\n", result);
    return 0;
}