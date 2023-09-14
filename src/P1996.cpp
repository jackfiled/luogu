#include <cstdio>
#include <vector>
#include <list>

using namespace std;

int main()
{
    vector<int> result;
    list<int> students;

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        students.push_back(i);
    }

    int pos = 1;
    auto i = students.begin();
    while (!students.empty())
    {
        if (pos == m)
        {
            result.push_back(*i);
            auto temp = i;
            i++;
            students.erase(temp);

            pos = 0;
        }
        else
        {
            i++;
        }

        pos++;
        if (i == students.end())
        {
            i = students.begin();
        }
    }

    for (auto n : result)
    {
        printf("%d ", n);
    }
    printf("\n");
    return 0;
}