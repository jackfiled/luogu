#include <cstdio>
#include <unordered_set>

void real()
{
    int number;
    scanf("%d", &number);

    std::unordered_set<int> s;

    for (int i = 0; i < number; i++)
    {
        int t;
        scanf("%d", &t);
        
        if (s.count(t) == 0)
        {
            printf("%d ", t);
            s.emplace(t);
        }
    }
    printf("\n");
}

int main()
{
    int number;
    scanf("%d", &number);

    for (int i = 0; i < number; i++)
    {
        real();
    }

    return 0;
}