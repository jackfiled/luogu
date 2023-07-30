#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct Position {
    int x;
    int y;
    int z;
};

double distance(const Position& a, const Position& b)
{
    double sum = (a.x - b.x) * (a.x - b.x);
    sum += (a.y - b.y) * (a.y - b.y);
    sum += (a.z - b.z) * (a.z - b.z);

    return sqrt(sum);
}

bool compare(const Position& a, const Position& b)
{
    return a.z < b.z;
}

int main()
{
    int number;
    scanf("%d", &number);

    Position positions[number];
    for (int i = 0; i < number; i++)
    {
        scanf("%d %d %d", &positions[i].x, &positions[i].y, &positions[i].z);
    }

    double sum = 0;
    sort(positions, positions + number, compare);

    for(int i = 0; i < number - 1; i++)
    {
        sum += distance(positions[i], positions[i + 1]);
    }

    printf("%.3lf\n", sum);
    return 0;
}

