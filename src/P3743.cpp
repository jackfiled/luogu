#include <cstdio>

struct Infra
{
    double v, e;
};

int main()
{
    int number;
    double p;
    scanf("%d %lf", &number, &p);
    double v_sum = 0;
    Infra infras[number];

    for (int i = 0; i < number; i++)
    {
        scanf("%lf %lf", &infras[i].v, &infras[i].e);
        v_sum += infras[i].v;
    }

    if (p >= v_sum)
    {
        printf("-1\n");
        return 0;
    }
    
    double left = 0;
    double right = 1e10;

    while (right - left > 1e-6)
    {
        double middle = (left + right) / 2;

        double energy = 0;
        for (int i = 0; i < number; i++)
        {
            if (infras[i].e >= infras[i].v * middle)
            {
                continue;
            }

            energy += infras[i].v * middle - infras[i].e;
        }

        if (energy > p * middle)
        {
            right = middle;
        }
        else
        {
            left = middle;
        }
    }

    printf("%lf\n", left);
    return 0;
}