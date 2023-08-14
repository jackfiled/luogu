#include <cstdio>
#include <algorithm>

using namespace std;

struct Bill
{
    int weight;
    int value;
    float price;
};

bool compare(const Bill& a, const Bill& b)
{
    return a.value * b.weight > b.value * a.weight;
}

int main()
{
    int number, bag;
    scanf("%d %d", &number, &bag);

    Bill bills[number];
    
    for (int i = 0; i < number; i++)
    {
        scanf("%d %d", &bills[i].weight, &bills[i].value);

        bills[i].price = (float)bills[i].value / (float)bills[i].weight;
    }

    sort(bills, bills + number, compare);

    int now = 0, i = 0;
    float totol = 0;
    for (; i < number; i++)
    {
        if (bills[i].weight > bag - now)
        {
            break;
        }

        totol += bills[i].value;
        now += bills[i].weight;
    }

    if (i < number and now < bag)
    {
        totol += bills[i].price * (bag - now);
    }

    printf("%.2f\n", totol);
    return 0;
}