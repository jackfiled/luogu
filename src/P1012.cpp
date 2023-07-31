#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

bool compare(const int& a, const int& b)
{
    string a1 = to_string(a);
    string b1 = to_string(b);

    return a1 + b1 > b1 + a1;
}

int main()
{
    int number;
    scanf("%d", &number);

    int array[number];
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &array[i]);
    }

    sort(array, array + number, compare);

    for (int i = 0; i < number; i++)
    {
        printf("%d", array[i]);
    }
    printf("\n");
    return 0;
}