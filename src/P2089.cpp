#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct Ingredient {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
};

int main()
{
    int target;
    scanf("%d", &target);

    if (target < 10 or target > 30)
    {
        printf("0\n");
        return 0;
    }

    queue<Ingredient> ingredients;
    for (int a = 1; a <=3; a++)
    {
        for (int b = 1; b <= 3; b++)
        {
            for (int c = 1; c <= 3; c++)
            {
                for (int d = 1; d <= 3; d++)
                {
                    for (int e = 1; e <= 3; e++)
                    {
                        for (int f = 1; f <= 3; f++)
                        {
                            for (int g = 1; g <= 3; g++)
                            {
                                for (int h = 1; h <= 3; h++)
                                {
                                    for (int i = 1; i <= 3; i++)
                                    {
                                        for (int j = 1; j <= 3; j++)
                                        {
                                            if (a+b+c+d+e+f+g+h+i+j == target)
                                            {
                                                Ingredient ingredient = {
                                                    .a = a,
                                                    .b = b,
                                                    .c = c,
                                                    .d = d,
                                                    .e = e,
                                                    .f = f,
                                                    .g = g,
                                                    .h = h,
                                                    .i = i,
                                                    .j = j
                                                };

                                                ingredients.push(ingredient);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    printf("%ld\n", ingredients.size());

    while (ingredients.empty() == false)
    {
        Ingredient i = ingredients.front();
        ingredients.pop();

        printf("%d %d %d %d %d %d %d %d %d %d\n", i.a, i.b, i.c, i.d, i.e, i.f, i.g, i.h, i.i, i.j);
    }

    return 0;
}