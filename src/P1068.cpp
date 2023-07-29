#include <cstdio>
#include <algorithm>

using namespace std;

struct Candidate {
    int id;
    int score;
};

bool compare(const Candidate& a, const Candidate& b)
{
    if (a.score == b.score)
    {
        return a.id < b.id;
    }

    return a.score > b.score;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    Candidate candidates[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &candidates[i].id, &candidates[i].score);
    }

    sort(candidates, candidates + n, compare);

    int target = m * 1.5 - 1;
    int actual = target;
    while (actual < n - 1)
    {
        if (candidates[actual + 1].score == candidates[actual].score)
        {
            actual++;
        }
        else
        {
            break;
        }
    }

    printf("%d %d\n", candidates[actual].score, actual + 1);
    
    for (int i = 0; i <= actual; i++)
    {
        printf("%d %d\n", candidates[i].id, candidates[i].score);
    }

    return 0;
}