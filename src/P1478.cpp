#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int number, strength;
    scanf("%d %d", &number, &strength);
    int height1, height2, height;
    scanf("%d %d", &height1, &height2);
    height = height1 + height2;

    int actualNumber = 0;
    int apples[number];
    for (int i = 0; i < number; i++)
    {
        int h, s;
        scanf("%d %d", &h, &s);
        if (h <= height)
        {
            apples[actualNumber] = s;
            actualNumber++;
        }
    }

    sort(apples, apples + actualNumber);

    int result = 0;
    for (int i = 0; i < actualNumber; i++)
    {
        if (strength < apples[i])
        {
            break;
        }

        strength -= apples[i];
        result++;
    }

    printf("%d\n", result);
    return 0;
}