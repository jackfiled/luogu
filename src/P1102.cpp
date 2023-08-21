#include <cstdio>
#include <map>

using namespace std;

int main()
{
    int number, c;
    map<int, int> m;
    scanf("%d %d", &number, &c);

    int array[number];
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &array[i]);
        m[array[i]]++;
        array[i] = array[i] - c;
    }

    long long result = 0;
    for (int i = 0; i < number; i++)
    {
        result += m[array[i]];
    }

    printf("%lld\n", result);

    return 0;
}