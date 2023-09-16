#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int memory[m];
    int size = 0;
    int pos = 0;
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        int input;
        scanf("%d", &input);

        bool flag = false;
        for (int j = 0; j < size; j++)
        {
            if (memory[j] == input)
            {
                flag = true;
                break;
            }
        }

        if (!flag)
        {
            result++;

            memory[pos] = input;
            pos++;
            pos = pos % m;

            if (size < m)
            {
                size++;
            }
        }
    }

    printf("%d\n", result);
    return 0;
}