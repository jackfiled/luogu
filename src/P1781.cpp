#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

struct Candidate{
    int id;
    string score;
};

bool compare(const Candidate& a, const Candidate& b)
{
    if(a.score.length() == b.score.length())
    {
        auto aItor = a.score.begin();
        auto bItor = b.score.begin();

        while(aItor != a.score.end() and bItor != b.score.end() and *aItor == *bItor)
        {
            aItor++;
            bItor++;
        }

        if (aItor != a.score.end() and bItor != b.score.end())
        {
            return *aItor > *bItor;
        }
        else
        {
            return true;
        }
    }

    return a.score.length() > b.score.length();
}

int main()
{
    int number;
    scanf("%d", &number);

    Candidate candidates[number];

    for (int i = 0; i < number; i++)
    {
        char input[200];
        scanf("%s", input);

        candidates[i].id = i + 1;
        candidates[i].score = string(input);
    }

    sort(candidates, candidates + number, compare);

    printf("%d\n%s\n", candidates[0].id, candidates[0].score.c_str());
    return 0;
}