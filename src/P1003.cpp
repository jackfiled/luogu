#include <cstdio>
#include <vector>

using namespace std;

class Carpet
{
public:
    int x;
    int y;
    int width;
    int height;
    int id;

    Carpet(int x, int y, int width, int height);
};

Carpet::Carpet(int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

int main()
{
    int number;
    scanf("%d", &number);
    vector<Carpet> carpets;

    for (int i = 1; i <= number; i++)
    {
        int x, y, width, height;
        scanf("%d %d %d %d", &x, &y, &width, &height);
        Carpet c(x, y, width, height);
        c.id = i;
        carpets.push_back(c);
    }

    int x, y;
    scanf("%d %d", &x, &y);

    int result = -1;
    for (auto i = carpets.begin(); i != carpets.end(); i++)
    {
        int deltaX = x - i->x;
        int deltaY = y - i->y;

        if (deltaX >= 0 and deltaX <= i->width)
        {
            if (deltaY >= 0 and deltaY <= i->height)
            {
                result = i->id;
            }
        }
    }
    printf("%d\n", result);

    return 0;
}