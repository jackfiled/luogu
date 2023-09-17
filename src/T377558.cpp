#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int n;
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++)
    {
        char input[100000];

        scanf("%s", input);
        string a(input);
        scanf("%s", input);
        string b(input);

        int result = 0;
        for (int i = 1; i < (int)b.size(); i++)
        {
            int j = b.size() - i;

            string x = a.substr(0, i);
            string y = a.substr(a.size() - j, j);
            string yx = y + x;

            if (yx == b)
            {
                result++;
            }
        }
        printf("%d\n", result);
    }
}