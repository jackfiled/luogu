#include <cstdio>
#include <cmath>

double load(double w0, double i, int m, double w)
{
    for (int j = 0; j < m; j++)
    {
        w0 = w0 * (1 + i) - w;
    }

    return w0;
}

int main()
{
    double w0, w;
    int m;
    scanf("%lf %lf %d", &w0, &w, &m);

    double left = 0, right = 5;

    double result = -1;
    while (right - left > 0.0001)
    {
        double middle = (left + right) / 2;

        double t = load(w0, middle, m, w);

        if (t > 0)
        {
            right = middle;
        }
        else if (t < 0)
        {
            left = middle;
        }
        else
        {
            result = middle;
            break;
        }
    }

    if (result == -1)
    {
        result = (left + right) / 2;
    }

    printf("%.1lf\n", result * 100);
    return 0;
}