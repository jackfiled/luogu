#include <cstdio>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int scores[n + 1];

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &scores[i]);
    }

    int result = 0;
    for (int i = 1; i <= m; i++)
    {
        int student;
        scanf("%d", &student);

        if (student >= 1 and student <= n)
        {
            if (scores[student] < 200)
            {
                result++;
            }
        }
    }

    printf("%d\n", result);
    return 0;
}