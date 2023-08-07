#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct Ingredient {
    int bitterness;
    int sourness;
};

class DFS 
{
public:
    int distance;
    int target;
    Ingredient *array;
    int length;

    DFS(Ingredient *array, int length)
    {
        this->array = array;
        this->length = length;
        distance = 0x7fffffff;
    }

    void dfs(int now, int totolBitterness, int totolSourness)
    {
        if (now >= length)
        {
            if (totolBitterness == 0 and totolSourness == 1)
            {
                return;
            }

            distance = min(distance, abs(totolBitterness - totolSourness));
            return;
        }

        dfs(now + 1, totolBitterness + array[now].bitterness, totolSourness * array[now].sourness);
        dfs(now + 1, totolBitterness, totolSourness);
    }
};

int main()
{
    int number;
    scanf("%d", &number);
    Ingredient ingredients[number];
    for (int i = 0; i < number; i++)
    {
        scanf("%d %d", &ingredients[i].sourness, &ingredients[i].bitterness);
    }

    DFS dfs(ingredients, number);
    dfs.dfs(0, 0, 1);

    printf("%d\n", dfs.distance);
}