#include <cstdio>
#include <cmath>

double func(double a, double b, double c, double d, double x)
{
    return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}

int main()
{
    double a, b, c, d;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

    int count = 0;
    for (int i = -100; i < 100; i++)
    {
        double x1 = func(a, b, c, d, i);
        double x2 = func(a, b, c, d, i + 1);

        if (x1 == 0)
        {
            printf("%.2lf ", (double)i);
            count++;
        }

        if (x1 * x2 < 0)
        {
            double left = i, right = i + 1;
            while (right - left > 0.001)
            {
                double middle = (left + right) / 2;
                double m = func(a, b, c, d, middle);

                if (m * x1 <= 0)
                {
                    right = middle;
                }
                else
                {
                    left = middle;
                }
            }

            printf("%.2lf ", right);
            count++;
        }

        if (count == 3)
        {
            printf("\n");
            break;
        }
    }

    return 0;
}