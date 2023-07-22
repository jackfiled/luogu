#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    set<int> s;
    int number;
    scanf("%d", &number);

    for (int i = 0; i < number; i++)
    {
        int input;
        scanf("%d", &input);
        s.insert(input);
    }

    printf("%ld\n", s.size());
    for (auto i = s.begin(); i != s.end(); i++)
    {
        printf("%d", *i);
        auto temp = i;
        temp++;
        if (temp != s.end())
        {
            printf(" ");
        }
    }
    printf("\n");
    

    return 0;
}